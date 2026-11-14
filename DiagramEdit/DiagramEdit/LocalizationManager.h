#pragma once

#include <map>
#include <string>
#include <windows.h>

// Loads UTF-8 localization files and provides Japanese fallback text.
// Keys use the form "Section.Key", for example "Common.OK".
class CLocalizationManager
{
public:
    CLocalizationManager();

    // Loads a UTF-8 INI-style file. Supported language codes: ja, en, ko.
    // Returns false when the file is missing, malformed UTF-8, or unsupported.
    bool Load(const std::wstring& filePath, const std::string& languageCode);

    // Returns the translated value, or fallbackText when the key is absent.
    void ApplyToDialog(HWND dialog) const;
    void ApplyToMenu(HMENU menu) const;
    std::wstring TranslateText(const std::wstring& original) const;

    std::wstring GetText(
        const std::wstring& key,
        const std::wstring& fallbackText) const;

    const std::string& GetLanguageCode() const;
    void SetLanguageCode(const std::string& languageCode);

private:
    std::string m_languageCode;
    std::map<std::wstring, std::wstring> m_texts;
};

// Translates a complete UI message when a matching Text entry exists.
std::wstring LocalizeUiText(const std::wstring& original);
