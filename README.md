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
uploading \*.ino sketches to the keyboard.

- <https://kaleidoscope.readthedocs.io/en/latest/quick_start.html>

The `compile` script will do the following:

- Create a header file that may contain macros with personal info. This header
  need to be completed by the user before compiling. After creation, compilation
  is aborted.
- If the `personal_macros.h` file exists, `arduino-cli` will be called to
  compile the sketch.

Similarly to the compile script, the `upload` script uploads the firmware to the
keyboard. Make sure you hold the left key on the bottom row during uploading.
This will put the keyboard in "program mode".

### Tips

- Factory reset the Atreus using Chrysalis before uploading sketches for the
  first time.
- In neovim add the arduino-language-server using lsp-config.
- Save a backup of your latest layout using Chrysalis.
- An example of a config file can be found [here](https://github.com/BartSte/dotfiles-linux/tree/master/dotfiles-linux/arduino).
- If you do not have permission to accesses the /dev/ttyACM0 device, you can do
  the following:
  - run: `sudo chmod a+rw /dev/ttyACM0`
  - run as root and use the `--config-file` option to point to the config file.
