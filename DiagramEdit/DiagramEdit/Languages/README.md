# Localization files

The application supports three language codes:

- `ja`: Japanese (default)
- `en`: English
- `ko`: Korean

Each file is UTF-8 encoded and uses INI-style sections. Keep section/key names identical across all language files. Add menu commands under `[Menu]`, language settings under `[Settings]`, shared buttons under `[Common]`, and dialog, menu-popup, fixed option-list, toolbar tooltip, status-bar, file-filter, and message text under `[Text]`.

Example:

```ini
[Menu]
File=&File
New=&New\tCtrl+N
```

The `[Text]` section currently contains the shared UI translation catalog. Use the Japanese source text itself as each key (without a `Text.` prefix); the loader indexes entries under `Text.<key>`. Escape line breaks as `\\n` and tabs as `\\t`. Fixed option lists are translated explicitly, while user-authored station, train, and diagram names remain unchanged.\n\nThe language code is stored in the user's `OuDia.ini` profile under `[AppProp]` as `Language=ja|en|ko`. A language selection is applied after restarting the application.

Japanese remains the fallback language when a translation key is missing. User-authored railway data such as station names, train names, and diagram names is not translated.
