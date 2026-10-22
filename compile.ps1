$ErrorActionPreference = "Stop"

$Directory = $PSScriptRoot
$Fqbn = "keyboardio:avr:keyboardio_atreus"
$BuildDirectory = Join-Path $Directory ("build\" + $Fqbn.Replace(":", "."))
$PersonalMacros = Join-Path $Directory "personal_macros.h"
$TemplateMacros = Join-Path $Directory "template_personal_macros.h"
$ConfigFile = Join-Path $env:LOCALAPPDATA "Arduino15\arduino-cli.yaml"

if (-not (Test-Path -LiteralPath $PersonalMacros)) {
    Copy-Item -LiteralPath $TemplateMacros -Destination $PersonalMacros
    Write-Host "Created personal_macros.h"
    Write-Host "Please finalize your personal macros."
    exit 1
}

& arduino-cli compile --config-file $ConfigFile --fqbn $Fqbn --output-dir $BuildDirectory $Directory
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}
