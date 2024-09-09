@echo off

@rem cambio de imagen
set IMAGENAME=minix3hd.plot
set IMAGEZIP=%IMAGENAME%.7z
set IMAGEUNZIP=%IMAGENAME%.qcow2

@rem verificamos las herramientas
if exist .\utilidades\qemu\qemu-system-x86_64w.exe if exist .\imagen\%IMAGEUNZIP% goto tools_ok
    echo ERROR: No se encuentran las herramientas necesarias para arrancar la máquina virtual
    echo Por favor, descomprime las herramientas y la imagen de Minix
    echo .\utilidades\descomprimir.bat
    goto label_fin
:tools_ok

@rem Verificar que existe una ejecución del httptar con los comando task, si no existe mensaje de error y salir
tasklist /FI "IMAGENAME eq httptar.exe" 2>NUL | find /I "httptar.exe" >NUL
if %ERRORLEVEL% == 0 goto htar_ok
    echo ERROR No se encuentra el servidor HTTPServer
    echo Por favor, abre otra terminal y ejecuta el comando
    echo .\utilidades\httptar.exe
    goto label_fin
:htar_ok

echo Estableciendo directorio temporal local
set RUTATRABAJO=.\
subst M: %RUTATRABAJO%
echo M: %RUTATRABAJO%

@rem leeamos su matrícula
set /p ID=<id.txt
set "ID=%ID: =%"
set IMAGEFILE=%IMAGENAME%.%ID%.qcow2
set MINIX_PATH=M:\imagen\%IMAGEFILE%
echo Trabajaremos con %MINIX_PATH%

set MINIXOUT=.\out
if exist %MINIXOUT% goto out_dir_created
    mkdir %MINIXOUT%
:out_dir_created

echo Todo bien :)
echo Arrancamos Minix

M:utilidades\qemu\qemu-system-x86_64w.exe ^
-cpu "pentium3" ^
-m 512 ^
-name %ID% ^
-rtc base=localtime ^
-hda %MINIX_PATH% ^
-drive file=fat:rw:%MINIXOUT%,format=raw,media=disk,cache=none ^
-netdev user,id=n1,ipv6=off,restrict=off,hostfwd=tcp:127.0.0.1:5522-:22 -device ne2k_pci,netdev=n1,mac=52:54:98:76:54:32 ^
-debugcon file:.\log_e9.bin

@rem Elementos útiles para la configuración de la máquina virtual.
@rem 
@rem Arranca con el CD para instalar
@rem -cdrom .\imagen\minix3_1_2a_ide_build2.iso ^
@rem
@rem Abre la imagen para hacer modificaciones
@rem -hda .\imagen\minix3hd.qcow2 ^
@rem -hda .\imagen\minix3hd.plot.qcow2 ^
@rem -hda %MINIX_PATH% ^
@rem
@rem Pruebas
@rem -net nic,model=ne2k_pci -nic user
@rem -netdev user,id=n1,ipv6=off,restrict=off ^
@rem -device ne2k_pci,netdev=n1,mac=52:54:98:76:54:32 
@rem -device ne2k_pci,netdev=net0 ^
@rem -drive format=raw,file=.\disco.img 
@rem -drive file=fat:rw:.\out,format=raw,media=disk,cache=none

echo Has finalizado la ejecución de Minix

:label_fin_desconectando
@rem Eliminamos la unidad M: y N:
subst /D M:

:label_fin
echo Hasta la vista.
