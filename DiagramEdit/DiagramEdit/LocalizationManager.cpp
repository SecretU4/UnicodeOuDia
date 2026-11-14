#include "stdafx.h"
#include "LocalizationManager.h"

#include <windows.h>
#include <fstream>
#include <sstream>
#include <vector>

namespace
{
    std::wstring Trim(const std::wstring& value)
    {
        const std::wstring whitespace = L" \t\r\n";
        const std::wstring::size_type first = value.find_first_not_of(whitespace);
        if (first == std::wstring::npos)
        {
            return std::wstring();
        }
        const std::wstring::size_type last = value.find_last_not_of(whitespace);
        return value.substr(first, last - first + 1);
    }

    bool IsSupportedLanguage(const std::string& languageCode)
    {
        return languageCode == "ja" || languageCode == "en" || languageCode == "ko";
    }

    bool ReadUtf8File(const std::wstring& filePath, std::wstring* output)
    {
        if (output == NULL)
        {
            return false;
        }

        HANDLE file = CreateFileW(
            filePath.c_str(),
            GENERIC_READ,
            FILE_SHARE_READ,
            NULL,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            NULL);
        if (file == INVALID_HANDLE_VALUE)
        {
            return false;
        }

        LARGE_INTEGER fileSize;
        if (!GetFileSizeEx(file, &fileSize) ||
            fileSize.QuadPart < 0 ||
            fileSize.QuadPart > 4 * 1024 * 1024)
        {
            CloseHandle(file);
            return false;
        }

        std::vector<char> bytes(static_cast<size_t>(fileSize.QuadPart));
        DWORD bytesRead = 0;
        const BOOL readOk = bytes.empty() ||
            ReadFile(file, &bytes[0], static_cast<DWORD>(bytes.size()), &bytesRead, NULL);
        CloseHandle(file);

        if (!readOk || bytesRead != bytes.size())
        {
            return false;
        }

        if (bytes.empty())
        {
            output->clear();
            return true;
        }

        const int byteCount = static_cast<int>(bytes.size());
        int charCount = MultiByteToWideChar(
            CP_UTF8, MB_ERR_INVALID_CHARS, &bytes[0], byteCount, NULL, 0);
        if (charCount <= 0)
        {
            return false;
        }

        output->resize(charCount);
        if (MultiByteToWideChar(
                CP_UTF8, MB_ERR_INVALID_CHARS, &bytes[0], byteCount,
                &(*output)[0], charCount) != charCount)
        {
            output->clear();
            return false;
        }

        // Accept UTF-8 files with or without a BOM.
        if (!output->empty() && (*output)[0] == 0xFEFF)
        {
            output->erase(0, 1);
        }
        return true;
    }
}

namespace
{
    struct DialogTranslationContext
    {
        const CLocalizationManager* manager;
    };

    BOOL CALLBACK TranslateDialogChild(HWND window, LPARAM parameter)
    {
        DialogTranslationContext* context = reinterpret_cast<DialogTranslationContext*>(parameter);
        if (context == NULL || context->manager == NULL) return TRUE;
        const int length = GetWindowTextLengthW(window);
        if (length <= 0) return TRUE;
        std::vector<wchar_t> buffer(static_cast<size_t>(length) + 1);
        GetWindowTextW(window, &buffer[0], length + 1);
        const std::wstring original(&buffer[0]);
        const std::wstring translated = context->manager->GetText(L"Text." + original, original);
        if (translated != original) SetWindowTextW(window, translated.c_str());
        return TRUE;
    }
}

void CLocalizationManager::ApplyToDialog(HWND dialog) const
{
    if (dialog == NULL) return;
    const int length = GetWindowTextLengthW(dialog);
    if (length > 0)
    {
        std::vector<wchar_t> buffer(static_cast<size_t>(length) + 1);
        GetWindowTextW(dialog, &buffer[0], length + 1);
        const std::wstring original(&buffer[0]);
        const std::wstring translated = GetText(L"Text." + original, original);
        if (translated != original) SetWindowTextW(dialog, translated.c_str());
    }
    DialogTranslationContext context;
    context.manager = this;
    EnumChildWindows(dialog, TranslateDialogChild, reinterpret_cast<LPARAM>(&context));
}

CLocalizationManager::CLocalizationManager()
    : m_languageCode("ja")
{
}

bool CLocalizationManager::Load(
    const std::wstring& filePath,
    const std::string& languageCode)
{
    if (!IsSupportedLanguage(languageCode))
    {
        return false;
    }

    std::wstring contents;
    if (!ReadUtf8File(filePath, &contents))
    {
        return false;
    }

    std::map<std::wstring, std::wstring> loadedTexts;
    std::wistringstream stream(contents);
    std::wstring line;
    std::wstring section;

    while (std::getline(stream, line))
    {
        line = Trim(line);
        if (line.empty() || line[0] == L';' || line[0] == L'#')
        {
            continue;
        }

        if (line.size() >= 2 && line[0] == L'[' && line[line.size() - 1] == L']')
        {
            section = Trim(line.substr(1, line.size() - 2));
            continue;
        }

        const std::wstring::size_type separator = line.find(L'=');
        if (separator == std::wstring::npos || section.empty())
        {
            continue;
        }

        const std::wstring key = Trim(line.substr(0, separator));
        const std::wstring value = Trim(line.substr(separator + 1));
        if (!key.empty())
        {
            loadedTexts[section + L"." + key] = value;
        }
    }

    m_texts.swap(loadedTexts);
    m_languageCode = languageCode;
    return true;
}

std::wstring CLocalizationManager::GetText(
    const std::wstring& key,
    const std::wstring& fallbackText) const
{
    const std::map<std::wstring, std::wstring>::const_iterator found =
        m_texts.find(key);
    return found == m_texts.end() ? fallbackText : found->second;
}

const std::string& CLocalizationManager::GetLanguageCode() const
{
    return m_languageCode;
}

void CLocalizationManager::SetLanguageCode(const std::string& languageCode)
{
    if (IsSupportedLanguage(languageCode))
    {
        m_languageCode = languageCode;
    }
}
