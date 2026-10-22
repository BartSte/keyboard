$ErrorActionPreference = "Stop"

$KeyboardioUrl = "https://raw.githubusercontent.com/keyboardio/arduino-kaleidoscope-master/main/package_kaleidoscope_master_index.json"
$BadKeyboardioUrl = "[$KeyboardioUrl]"
$ConfigFile = Join-Path $env:LOCALAPPDATA "Arduino15\arduino-cli.yaml"

if (-not (Get-Command arduino-cli -ErrorAction SilentlyContinue)) {
    Write-Host "arduino-cli was not found on PATH."
    Write-Host "Install it with Scoop first: scoop install arduino-cli"
    exit 1
}

if (-not (Test-Path -LiteralPath $ConfigFile)) {
    & arduino-cli config init
    if ($LASTEXITCODE -ne 0) {
        exit $LASTEXITCODE
    }
}

$additionalUrls = & arduino-cli config get board_manager.additional_urls --config-file $ConfigFile
if ($additionalUrls -contains "- '$BadKeyboardioUrl'" -or $additionalUrls -contains "- $BadKeyboardioUrl") {
    & arduino-cli config remove board_manager.additional_urls $BadKeyboardioUrl --config-file $ConfigFile
    if ($LASTEXITCODE -ne 0) {
        exit $LASTEXITCODE
    }
}

$additionalUrls = & arduino-cli config get board_manager.additional_urls --config-file $ConfigFile
if (-not ($additionalUrls -contains "- $KeyboardioUrl")) {
    & arduino-cli config add board_manager.additional_urls $KeyboardioUrl --config-file $ConfigFile
    if ($LASTEXITCODE -ne 0) {
        exit $LASTEXITCODE
    }
}

& arduino-cli core update-index --config-file $ConfigFile
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

& arduino-cli core install keyboardio:avr --config-file $ConfigFile
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

Write-Host "Windows Arduino CLI setup complete."
