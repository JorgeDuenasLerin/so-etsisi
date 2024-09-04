@echo off

@rem leeamos su matrícula
set /p ID=<id.txt
set "ID=%ID: =%"

@rem Verificamos que hay una matrícula
if x%ID:TODO=%==x%ID% goto label_id_ok
    echo Debes modificar id.txt con tu identificador
    goto end
:label_id_ok

echo El identificador establecido es: %ID%

if exist .\utilidades\qemu goto label_qemu_ok
    echo No existe la carpeta de qemu. La creamos.
    .\utilidades\7za.exe -o".\utilidades\" -aoa  x .\utilidades\qemu.7z.001
    @rem .\utilidades\7za.exe a -v10m -t7z .\utilidades\qemu.7z .\utilidades\qemu
:label_qemu_ok

echo Qemu OK

@rem cambio de nombre de imagen minix3hd.7z por minix3hd.plot.7z

set IMAGENAME=minix3hd.plot
set IMAGEZIP=%IMAGENAME%.7z
set IMAGEUNZIP=%IMAGENAME%.qcow2
@rem .\imagen\minix3hd.xxx.%id%.qcow2 Esta será la imagen de trabajo.
if exist .\imagen\%IMAGEUNZIP% goto label_descomprimido
    .\utilidades\7za.exe -o".\imagen\"  e .\imagen\%IMAGEZIP%
:label_descomprimido

echo Existe imagen descomprimida. OK

set MINIX_PATH=.\imagen\%IMAGENAME%.%ID%.qcow2
if exist %MINIX_PATH% goto label_imagen_personal
    copy .\imagen\%IMAGEUNZIP% %MINIX_PATH%
:label_imagen_personal

echo Existe imagen personal. OK
echo %MINIX_PATH%

:label_fin
echo Tarea completada. Puedes arrancar minix.

:end