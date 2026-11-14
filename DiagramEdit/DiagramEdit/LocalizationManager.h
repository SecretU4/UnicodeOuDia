#pragma once

#include <map>
#include <string>

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
    std::wstring GetText(
        const std::wstring& key,
        const std::wstring& fallbackText) const;

    const std::string& GetLanguageCode() const;

private:
    std::string m_languageCode;
    std::map<std::wstring, std::wstring> m_texts;
};
