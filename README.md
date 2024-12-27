# keyboard

- [Keyboardio Atreus and Arduino CLI](https://shop.keyboard.io/products/keyboardio-atreus)

## Setup arduino-cli

Follow the instructions on the website of Arduino to setup `arduino-cli`:

- <https://arduino.github.io/arduino-cli/0.28/getting-started/>
  On Arch, install `arduino-cli` by running:

```bash
sudo pacman -S arduino-cli
```

After this, you need to install your board. In my case, this is the Atreus of
keyboardio. To install the board, run:

```bash
arduino-cli core install keyboardio:avr
```

## Configuration

Place the following config at `~/.arduino15/arduino-cli.yaml`:

```yaml
board_manager:
  additional_urls:
    - https://raw.githubusercontent.com/keyboardio/arduino-kaleidoscope-master/main/package_kaleidoscope_master_index.json
daemon:
  port: "50051"
directories:
  data: $HOME/.arduino15
  downloads: $HOME/.arduino15/staging
  user: $HOME/Arduino
library:
  enable_unsafe_install: false
logging:
  file:
  format: text
  level: debug
metrics:
  addr: :9090
  enabled: true
output:
  no_color: false
sketch:
  always_export_binaries: true
updater:
  enable_notification: true
```

Chances are that you need to change some details in the config file.

## Compiling

Follow the instructions on the site of kaleidoscope to enable compiling and
uploading \*.ino sketches to the keyboard.

- <https://kaleidoscope.readthedocs.io/en/latest/quick_start.html>

The `compile` script will do the following:

- Create a header file that may contain macros with personal info. This header
  need to be completed by the user before compiling. After creation, compilation
  is aborted.
- If the `personal_macros.h` file exists, `arduino-cli` will be called to
  compile the sketch.

## Uploading

Similarly to the compile script, the `upload` script uploads the firmware to
the keyboard. Make sure you hold the left key on the bottom row during
uploading (in case of the Atreus). This will put the keyboard in "program
mode".

If you encounter a permission error for accessing the `/dev/ttyACM0` device,
you can solve this in two ways:

1. Run the script as root:

   ```bash
    sudo ./upload --config-file $HOME/.arduino15/arduino-cli.yaml
   ```

2. Run the following command:

   ```bash
   sudo chmod a+rw /dev/ttyACM0
   ```

   Which will give all users read and write permissions to the device.

## Version tags

- Major increase means a breaking change.
- Minor increase means a change in keymaps was done.
- Patch increase means a code improvement

## Keymap

- Home row mods:
  - `a`: `Win`
  - `r`: `Alt`
  - `s`: `Shift`
  - `t`: `Ctrl`
  - `n`: `Ctrl`
  - `e`: `Alt`
  - `i`: `Shift`
  - `o`: `Win`

- Move to layer on hold:
  - `f`: `Numpad`
  - `u`: `Symbols`
  - `Tab`: `Navigation`
  - `Enter`: `Navigation`
  - `g`: `F-keys`


```plaintext
 ### Default Layer: COLEMAK-DH Layout
 ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 │  Q  │  W  │  F  │  P  │  B  │             │  J  │  L  │  U  │  Y  │  ;  │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │  A  │  R  │  S  │  T  │  G  │             │  M  │  N  │  E  │  I  │  O  │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │  Z  │  X  │  C  │  D  │  V  │             │  K  │  H  │  ,  │  .  │  /  │
 ├─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┤
 │ Br+ │ Br- │ Esc │ Tab │ Sp  │ Cps │ │ Mnu │ BkS │ Ent │ Del │ Vl+ │ Vl- │
 └─────┴─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘
                   
 ### Symbols Layer
 ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 │  !  │  @  │  #  │  $  │  %  │             │     │     │     │     │     │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │  {  │  [  │  (  │  '  │  `  │             │     │     │     │     │     │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │  }  │  ]  │  )  │  "  │  ~  │             │     │     │     │     │     │
 ├─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┤
 │     │     │     │  ^  │  _  │     │ │     │     │     │     │     │     │
 └─────┴─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘
 
 ### Numpad Layer
 ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 │     │     │     │     │     │             │  *  │  7  │  8  │  9  │  +  │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │             │  \  │  4  │  5  │  6  │  -  │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │             │  |  │  1  │  2  │  3  │  =  │
 ├─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │     │ │     │  =  │  0  │     │     │     │
 └─────┴─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘
 
 ### Navigation Layer
 ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 │     │     │     │     │     │             │ Home│PgDwn│PgUp │ End │Play │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │             │Left │Down │ Up  │Right│     │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │             │     │     │     │Prev │Next │
 ├─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │     │ │     │     │     │     │     │     │
 └─────┴─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘
 
 ### Function Keys Layer
 ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 │     │     │     │     │     │             │  F7 │  F8 │  F9 │ F10 │     │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │             │  F4 │  F5 │  F6 │ F11 │     │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │             │  F1 │  F2 │  F3 │ F12 │     │
 ├─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │     │ │     │     │     │     │     │     │
 └─────┴─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘
```

### Tips

- Factory reset the Atreus using Chrysalis before uploading sketches for the
  first time.
- In neovim add the arduino-language-server using lsp-config.
- Save a backup of your latest layout using Chrysalis.
