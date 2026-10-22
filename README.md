# keyboard

- [Keyboardio Atreus and Arduino CLI](https://shop.keyboard.io/products/keyboardio-atreus)

## Setup arduino-cli

Follow the instructions on the website of Arduino to setup `arduino-cli`:

- <https://arduino.github.io/arduino-cli/0.28/getting-started/>

On Windows with Scoop:

```powershell
scoop install arduino-cli
```

On Arch, install `arduino-cli` by running:

```bash
sudo pacman -S arduino-cli
```

## Configuration

On Windows, `setup-windows.ps1`, `compile.ps1`, and `upload.ps1` use the
Arduino CLI config at `%LOCALAPPDATA%\Arduino15\arduino-cli.yaml`.

On Linux or WSL, place the following config at `~/.arduino15/arduino-cli.yaml`:

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
  file: ""
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

## Install Keyboardio Core

On Windows, run:

```powershell
.\setup-windows.ps1
```

On Linux or WSL, run:

```bash
arduino-cli core update-index
arduino-cli core install keyboardio:avr
```

## Compiling

Follow the instructions on the site of kaleidoscope to enable compiling and
uploading \*.ino sketches to the keyboard.

- <https://kaleidoscope.readthedocs.io/en/latest/quick_start.html>

The `compile` script will do the following:

- Create a header file that may contain macros with personal info. This header
  needs to be completed by the user before compiling. After creation, compilation
  is aborted.
- If the `personal_macros.h` file exists, `arduino-cli` will be called to
  compile the sketch.
- Write the uploadable HEX file to
  `build/keyboardio.avr.keyboardio_atreus/keyboard.ino.hex`.

On Windows, use the PowerShell script instead:

```powershell
.\compile.ps1
```

Both scripts write the uploadable HEX file to
`build/keyboardio.avr.keyboardio_atreus/keyboard.ino.hex`.

## Uploading

Similarly to the compile script, the `upload` script uploads the firmware to
the keyboard. Make sure you hold the left key on the bottom row during
uploading (in case of the Atreus). This will put the keyboard in "program
mode".

Run `./compile` before `./upload`. The upload script does not compile; it
uploads the existing `build/keyboardio.avr.keyboardio_atreus/keyboard.ino.hex`
file.

If the keyboard appears on a different serial device, set `UPLOAD_PORT`:

```bash
sudo UPLOAD_PORT=/dev/ttyACM1 ./upload --config-file "$HOME/.arduino15/arduino-cli.yaml"
```

On Windows, use the PowerShell script with the keyboard's COM port:

```powershell
.\upload.ps1 -Port COM5
```

When more than one serial port is present, pass `-Port` explicitly. The script
will not guess between multiple COM ports.

If the port changes when the keyboard enters program mode, check Device Manager
or run this PowerShell command while holding the Prog key:

```powershell
[System.IO.Ports.SerialPort]::GetPortNames()
```

### Build in WSL2 and upload from Windows

WSL2 can build the firmware without access to the keyboard. Windows COM ports
do not automatically map to `/dev/ttyS*` in WSL2. Use Windows PowerShell for
the upload, or explicitly attach the USB device to WSL with `usbipd-win`.

For a Windows upload, use this procedure:

1. In WSL, build the firmware:

   ```bash
   cd /home/barts/code/personal/cpp/keyboard
   ./compile
   ```

2. In WSL, prepare the files for Windows:

   ```bash
   ./prepare-windows-upload
   ```

   The helper copies the setup script, upload script, and existing HEX file
   to `atreus-upload` inside your Windows temporary folder. It does not build
   or upload firmware. It prints a `Set-Location` command for Windows PowerShell.
   Open Windows PowerShell and run that command before the next step.

   To choose another destination, pass its WSL path:

   ```bash
   ./prepare-windows-upload "/mnt/c/Users/Bart/Downloads/atreus-upload"
   ```

   The helper finds Windows PowerShell on `PATH`, or at its standard location
   under `/mnt/c/Windows`. An explicit destination requires no PowerShell call.
   The private macro header stays in WSL. The HEX file contains any macro text
   that the firmware uses; keep it private too.

3. On the first Windows upload, install Arduino CLI and the Keyboardio core:

   ```powershell
   scoop install arduino-cli
   .\setup-windows.ps1
   ```

   Skip the Scoop command if Arduino CLI is already installed on Windows.
   The Windows installation is separate from the installation in WSL.

4. Hold the Atreus Prog key (the bottom-left key). Find its COM port in Device
   Manager, or run this command while you hold the key:

   ```powershell
   [System.IO.Ports.SerialPort]::GetPortNames()
   ```

   Use the keyboard's port in program mode. It can differ from its normal port.
   If several ports appear, identify the keyboard under Ports in Device Manager.

5. Keep the Prog key held. Replace `COM5` with the keyboard's port and run:

   ```powershell
   .\upload.ps1 -Port COM5
   ```

   Release the Prog key after the script reports completion. Try the new layer
   holds and a Meta-plus-number shortcut.

For later updates, repeat the build, copy, port identification, and upload steps.
The upload script uses the copied HEX file and does not rebuild it.

Microsoft documents [access to WSL files from Windows](https://learn.microsoft.com/en-us/windows/wsl/filesystems)
and the alternative [USB attachment procedure](https://learn.microsoft.com/en-us/windows/wsl/connect-usb).
An attached USB device is unavailable to Windows until you detach it.

If you encounter a permission error for accessing the serial device,
you can solve this in two ways:

1. Run the script as root:

   ```bash
   sudo ./upload --config-file "$HOME/.arduino15/arduino-cli.yaml"
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
  - `e`: `Shift`
  - `i`: `Alt`
  - `o`: `Win`

- Move to layer on hold:
  - `Tab`: `Numpad`
  - `Space`: `Navigation right`
  - `Enter`: `Symbols`
  - `f`: `F-keys`
  - `d`: `Macros right`
  - `h`: `Macros left`

Taps retain the base-layer action. `Backspace`, `g`, and `u` have no hold action.
Both macro layers keep their existing assignments.

For a window shortcut, hold `a` for Meta and `Tab` for the number layer.
Then press a digit on the right half. For example, the physical `.` key produces
`3`, so this chord sends Meta + 3. Meta is the Win/Super modifier.
The firmware sends the same shortcut on Linux and Windows; the host determines
its action. The former number layer with automatic Meta is removed.

Hold `f` for F-keys. `F1` through `F9` occupy the same positions as `1` through
`9` on the number layer. `F10`, `F11`, and `F12` occupy the rightmost column.

In the layer diagrams, blank cells fall through to lower layers. Explicit
modifiers appear as `GUI`, `Alt`, `Shift`, and `Ctrl`. The base diagram omits
the two inner keys above the bottom row: left `PrintScreen` and right `Shift+F10`.

```plaintext
 ### Default Layer: COLEMAK-DH Layout
 ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 │  Q  │  W  │  F  │  P  │  B  │             │  J  │  L  │  U  │  Y  │  ;  │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │  A  │  R  │  S  │  T  │  G  │             │  M  │  N  │  E  │  I  │  O  │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │  Z  │  X  │  C  │  D  │  V  │             │  K  │  H  │  ,  │  .  │  /  │
 ├─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┤
 │ Br+ │ Br- │ Esc │ Tab │ Sp  │ Cps │ │ Dsp │ BkS │ Ent │ Del │ Vl- │ Vl+ │
 └─────┴─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘

 ### Symbols Layer
 ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 │  !  │  @  │  #  │  $  │  %  │             │     │     │     │     │     │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │  {  │  [  │  (  │  '  │  `  │             │     │Ctrl │Shift│ Alt │ GUI │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │  }  │  ]  │  )  │  "  │  ~  │             │     │     │     │     │     │
 ├─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┤
 │     │     │     │  ^  │  _  │     │ │     │     │     │     │     │     │
 └─────┴─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘

 ### Numpad Layer
 ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 │     │     │     │     │     │             │  *  │  7  │  8  │  9  │  +  │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │ GUI │ Alt │Shift│Ctrl │     │             │  \  │  4  │  5  │  6  │  -  │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │             │  |  │  1  │  2  │  3  │  &  │
 ├─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │     │ │     │  =  │  0  │  ,  │  .  │     │
 └─────┴─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘

 ### Navigation Right Layer
 ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 │     │     │     │     │     │             │ Home│PgDwn│PgUp │ End │Play │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │ GUI │ Alt │Shift│Ctrl │     │             │Left │Down │ Up  │Right│     │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │             │     │     │     │Prev │Next │
 ├─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │     │ │     │     │     │     │     │     │
 └─────┴─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘

 ### Function Keys Layer
 ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 │     │     │     │     │     │             │Pause│  F7 │  F8 │  F9 │ F10 │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │ GUI │ Alt │Shift│Ctrl │     │             │ScrLk│  F4 │  F5 │  F6 │ F11 │
 ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │             │ Ins │  F1 │  F2 │  F3 │ F12 │
 ├─────┼─────┼─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┼─────┼─────┤
 │     │     │     │     │     │     │ │     │     │     │     │     │     │
 └─────┴─────┴─────┴─────┴─────┴─────┘ └─────┴─────┴─────┴─────┴─────┴─────┘
```

### Tips

- Factory reset the Atreus using Chrysalis before uploading sketches for the
  first time.
- In neovim add the arduino-language-server using lsp-config.
- Save a backup of your latest layout using Chrysalis.
