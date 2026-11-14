#include "stdafx.h"
#include "LocalizationManager.h"
#include "DiagramEdit.h"

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
    std::wstring MakeDialogTextKey(const std::wstring& text)
    {
        const std::wstring normalized = Trim(text);
        std::wstring key = L"Text.";
        for (size_t i = 0; i < normalized.size(); ++i)
        {
            if (normalized[i] == L'\r') continue;
            if (text[i] == L'\n') key += L"\\n";
            else key += text[i];
        }
        return key;
    }

    std::wstring TranslateDialogText(
        const CLocalizationManager* manager,
        const std::wstring& original)
    {
        return manager == NULL ? original :
            manager->GetText(MakeDialogTextKey(original), original);
    }

    struct DialogTranslationContext
    {
        const CLocalizationManager* manager;
    };

    BOOL CALLBACK TranslateDialogChild(HWND window, LPARAM parameter)
    {
        DialogTranslationContext* context = reinterpret_cast<DialogTranslationContext*>(parameter);
        if (context == NULL || context->manager == NULL) return TRUE;

        const int length = GetWindowTextLengthW(window);
        if (length > 0)
        {
            std::vector<wchar_t> buffer(static_cast<size_t>(length) + 1);
            GetWindowTextW(window, &buffer[0], length + 1);
            const std::wstring original(&buffer[0]);
            const std::wstring translated = TranslateDialogText(context->manager, original);
            if (translated != original) SetWindowTextW(window, translated.c_str());
        }
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
        const std::wstring translated = TranslateDialogText(this, original);
        if (translated != original) SetWindowTextW(dialog, translated.c_str());
    }
    DialogTranslationContext context;
    context.manager = this;
    EnumChildWindows(dialog, TranslateDialogChild, reinterpret_cast<LPARAM>(&context));
}

namespace
{
    void TranslateMenuTree(HMENU menu, const CLocalizationManager* manager)
    {
        if (menu == NULL || manager == NULL) return;
        const int count = GetMenuItemCount(menu);
        for (int i = 0; i < count; ++i)
        {
            wchar_t buffer[512] = {};
            MENUITEMINFOW info = {};
            info.cbSize = sizeof(info);
            info.fMask = MIIM_SUBMENU | MIIM_STRING;
            info.dwTypeData = buffer;
            info.cch = 511;
            if (!GetMenuItemInfoW(menu, static_cast<UINT>(i), TRUE, &info)) continue;
            if (info.hSubMenu != NULL) TranslateMenuTree(info.hSubMenu, manager);

            std::wstring current(buffer);
            const std::wstring::size_type tab = current.find(L'\t');
            const std::wstring label = tab == std::wstring::npos ? current : current.substr(0, tab);
            const std::wstring suffix = tab == std::wstring::npos ? std::wstring() : current.substr(tab);
            const std::wstring translated = manager->GetText(L"Text." + label, label) + suffix;
            if (translated != current)
            {
                MENUITEMINFOW update = {};
                update.cbSize = sizeof(update);
                update.fMask = MIIM_STRING;
                update.dwTypeData = const_cast<LPWSTR>(translated.c_str());
                SetMenuItemInfoW(menu, static_cast<UINT>(i), TRUE, &update);
            }
        }
    }
}

void CLocalizationManager::ApplyToMenu(HMENU menu) const
{
    TranslateMenuTree(menu, this);
}

std::wstring CLocalizationManager::TranslateText(const std::wstring& original) const
{
    const std::wstring exact = TranslateDialogText(this, original);
    if (exact != original) return exact;

    const std::wstring normalized = MakeDialogTextKey(original).substr(5);
    for (std::map<std::wstring, std::wstring>::const_iterator entry = m_texts.begin();
         entry != m_texts.end(); ++entry)
    {
        const std::wstring prefix = L"Text.";
        if (entry->first.compare(0, prefix.size(), prefix) != 0) continue;
        const std::wstring pattern = entry->first.substr(prefix.size());
        if (pattern.find(L"%s") == std::wstring::npos &&
            pattern.find(L"%d") == std::wstring::npos) continue;

        std::vector<std::wstring> captures;
        size_t p = 0;
        size_t t = 0;
        bool matched = true;
        while (p < pattern.size())
        {
            if (pattern[p] == L'%' && p + 1 < pattern.size() &&
                (pattern[p + 1] == L's' || pattern[p + 1] == L'd'))
            {
                p += 2;
                size_t next = p;
                while (next < pattern.size() &&
                    !(pattern[next] == L'%' && next + 1 < pattern.size() &&
                      (pattern[next + 1] == L's' || pattern[next + 1] == L'd')))
                    ++next;
                const std::wstring literal = pattern.substr(p, next - p);
                const size_t found = literal.empty() ? normalized.size() :
                    normalized.find(literal, t);
                if (found == std::wstring::npos || found < t)
                {
                    matched = false;
                    break;
                }
                captures.push_back(normalized.substr(t, found - t));
                t = found;
            }
            else
            {
                size_t next = p;
                while (next < pattern.size() &&
                    !(pattern[next] == L'%' && next + 1 < pattern.size() &&
                      (pattern[next + 1] == L's' || pattern[next + 1] == L'd')))
                    ++next;
                const std::wstring literal = pattern.substr(p, next - p);
                if (normalized.compare(t, literal.size(), literal) != 0)
                {
                    matched = false;
                    break;
                }
                t += literal.size();
                p = next;
            }
        }
        if (!matched || t != normalized.size()) continue;

        std::wstring translated;
        size_t capture = 0;
        for (size_t i = 0; i < entry->second.size(); ++i)
        {
            if (entry->second[i] == L'%' && i + 1 < entry->second.size() &&
                (entry->second[i + 1] == L's' || entry->second[i + 1] == L'd'))
            {
                if (capture < captures.size()) translated += captures[capture++];
                ++i;
            }
            else
            {
                translated += entry->second[i];
            }
        }
        return translated;
    }
    return original;
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
        std::wstring value = Trim(line.substr(separator + 1));
        for (size_t escape = 0; (escape = value.find(L"\\n", escape)) != std::wstring::npos; )
        {
            value.replace(escape, 2, L"\n");
            ++escape;
        }
        for (size_t escape = 0; (escape = value.find(L"\\t", escape)) != std::wstring::npos; )
        {
            value.replace(escape, 2, L"\t");
            ++escape;
        }
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

std::wstring LocalizeUiText(const std::wstring& original)
{
    CDiagramEditApp* app = static_cast<CDiagramEditApp*>(AfxGetApp());
    return app == NULL ? original : app->getLocalizationManager().TranslateText(original);
}
