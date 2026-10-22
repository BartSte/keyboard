param(
    [string] $Port = $env:UPLOAD_PORT,
    [Parameter(ValueFromRemainingArguments = $true)]
    [string[]] $ArduinoArgs
)

$ErrorActionPreference = "Stop"

$Directory = $PSScriptRoot
$Fqbn = "keyboardio:avr:keyboardio_atreus"
$BuildDirectory = Join-Path $Directory ("build\" + $Fqbn.Replace(":", "."))
$HexFile = Join-Path $BuildDirectory "keyboard.ino.hex"
$ConfigFile = Join-Path $env:LOCALAPPDATA "Arduino15\arduino-cli.yaml"

if (-not (Test-Path -LiteralPath $HexFile)) {
    Write-Host "Compiled sketch not found: $HexFile"
    Write-Host "Run .\compile.ps1 first, then retry upload."
    exit 1
}

Write-Host "Hold down the Prog key on your keyboard now and keep it down."
Start-Sleep -Seconds 2

if ([string]::IsNullOrWhiteSpace($Port)) {
    Write-Host "Waiting for keyboard upload port..."
    $deadline = (Get-Date).AddSeconds(30)
    while ((Get-Date) -lt $deadline) {
        $ports = [System.IO.Ports.SerialPort]::GetPortNames() | Sort-Object
        if ($ports.Count -eq 1) {
            $Port = $ports[0]
            break
        }
        if ($ports.Count -gt 1) {
            Write-Host "Multiple serial ports are present: $($ports -join ', ')"
            Write-Host "Retry with the keyboard COM port, for example: .\upload.ps1 -Port COM5"
            exit 1
        }
        Start-Sleep -Seconds 1
    }
}

if ([string]::IsNullOrWhiteSpace($Port)) {
    Write-Host "No keyboard upload port found."
    Write-Host "Check Device Manager for the keyboard COM port, then retry with -Port COM5."
    exit 1
}

& arduino-cli upload `
    --config-file $ConfigFile `
    --port $Port `
    --fqbn $Fqbn `
    --input-file $HexFile `
    --discovery-timeout 30s `
    --verbose `
    @ArduinoArgs

if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

Write-Host "Done. You can let go of the Prog key now."
