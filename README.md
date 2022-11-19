# keyboard
- [Keyboardio Atreus and Arduino CLI](https://shop.keyboard.io/products/keyboardio-atreus)

## Setup arduino-cli
Follow the instructions on the website of Arduino to setup `arduino-cli`:
- <https://arduino.github.io/arduino-cli/0.28/getting-started/>
On Arch, install `arduino-cli` by running:
```bash
sudo pacman -S arduino-cli
```

## Compiling and uploading to keyboard
Follow the instructions on the site of kaleidoscope to enable compiling and
uploading *.ino sketches to the keyboard.
- <https://kaleidoscope.readthedocs.io/en/latest/quick_start.html>

### Tips
- Factory reset the Atreus using Chrysalis before uploading sketches for the
  first time.
- In neovim add the arduino-language-server using lsp-config.
- Save a backup of your latest layout using Chrysalis.
