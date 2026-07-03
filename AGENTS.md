# AGENTS.md

## Project

This repo is a Keyboardio Atreus firmware sketch built with Arduino CLI and Kaleidoscope.

## Working Rules

- Keep responses direct and concise.
- Treat `personal_macros.h` as private local data. It is ignored by git; do not print its values, stage it, or commit it.
- When adding, removing, or renaming a macro, keep `macros.h`, `macros.cpp`, `keymaps.h`, and `template_personal_macros.h` in sync.
- Keep README keymap notes and diagrams in sync with `keymaps.h` and `qukeys.cpp`.
- Do not commit generated firmware artifacts from `build/`.
- Do not run `./upload` unless explicitly asked; it targets `/dev/ttyACM0` and writes to the keyboard.

## Validation

- Run `git diff --check` before committing.
- Run `./compile` after firmware changes.
- If `arduino-cli` panics while parsing config, check that `logging.file` is an explicit string, for example `file: ""`, not a bare null value.
- A normal successful build reports sketch and global variable memory usage.

## Layout Notes

- `keymaps.h` is the source of truth for layer contents.
- `qukeys.cpp` is the source of truth for hold behavior and layer triggers.
- Each `KEYMAP_STACKED` layer should contain 44 key entries.
- `MACROS_LEFT` and `MACROS_RIGHT` are reached via Qukeys, not by ordinary layer keys in `keymaps.h`.
