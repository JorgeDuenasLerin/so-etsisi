@echo off

:: Guardar el directorio actual
set "folder=%~dp0"
set "folder=%folder:~0,-1%"

:: Comprobar los argumentos
if "%~1"=="-c" (
    set "folder=%CD%"
) else if not "%~1"=="" (
    set "folder=%~1"
)

:: Comprobar si se esta ejecutando como administrador
net session >nul 2>&1
if %errorLevel% NEQ 0 (
    echo Se requieren privilegios de administrador.
    echo Iniciando con privilegios elevados...

    :: Relanzar el script con permisos de administrador y pasar el directorio actual
    powershell -Command "Start-Process cmd -ArgumentList '/c \"\"%~dpnx0\" \"%folder%\"\"' -Verb RunAs"

    :: Salir si no se ha dado los permisos
    exit /b
)

:: Llamar a PowerShell para agregar la exclusion
PowerShell -Command "Add-MpPreference -ExclusionPath '%folder%'"

echo La carpeta %folder% ha sido agregada a las exclusiones de Windows Defender.
pause
