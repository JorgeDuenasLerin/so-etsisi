@echo off

@rem verificamos las herramientas
if exist .\utilidades\qemu\qemu-system-i386w.exe if exist .\imagen\minix3hd.qcow2 goto tools_ok
    echo ERROR: No se encuentran las herramientas necesarias para arrancar la máquina virtual
    echo Por favor, descomprime las herramientas y la imagen de Minix
    echo .\utilidades\descomprimir.bat
    goto label_fin
:tools_ok

@rem leeamos su matrícula
set /p ID=<id.txt
set MINIX_PATH=.\imagen\minix3hd.%ID%.qcow2
echo %MINIX_PATH%

@rem Verificar que existe una ejecución del httptar con los comando task, si no existe mensaje de error y salir
tasklist /FI "IMAGENAME eq httptar.exe" 2>NUL | find /I "httptar.exe" >NUL
if %ERRORLEVEL% == 0 goto htar_ok
    echo ERROR No se encuentra el servidor HTTPServer
    echo Por favor, abre otra terminal y ejecuta el comando
    echo .\utilidades\httptar.exe
    goto label_fin
:htar_ok

echo Creamos unidad U: para el USB de los alumnxs
@rem Establecemos la variable al directorio local. Será el USB de los alumnxs
set UUSB=.\
@rem Estará disponible en U:
subst U: %UUSB%

echo Todo bien :)
echo Arrancamos Minix

.\utilidades\qemu\qemu-system-i386w.exe ^
-cpu "pentium3" ^
-m 512 ^
-rtc base=localtime ^
-hda %MINIX_PATH% ^
-netdev user,id=n1,ipv6=off,restrict=off,hostfwd=tcp:127.0.0.1:5522-:22 -device ne2k_pci,netdev=n1,mac=52:54:98:76:54:32

@rem Elementos útiles para la configuración de la máquina virtual.
@rem 
@rem Arranca con el CD para instalar
@rem -cdrom .\imagen\minix3_1_2a_ide_build2.iso ^
@rem
@rem Abre la imagen para hacer modificaciones
@rem -hda .\imagen\minix3hd.qcow2 ^
@rem -hda %MINIX_PATH% ^
@rem
@rem Pruebas
@rem -net nic,model=ne2k_pci -nic user
@rem -netdev user,id=n1,ipv6=off,restrict=off ^
@rem -device ne2k_pci,netdev=n1,mac=52:54:98:76:54:32 
@rem -device ne2k_pci,netdev=net0 ^
@rem -drive format=raw,file=.\disco.img 
@rem -drive file=fat:rw:.\Trabajo,format=raw,media=disk,cache=none
@rem -drive file=fat:rw:.\Trabajo,format=raw,media=disk,cache=none

@rem Eliminamos la unidad U:
subst /D U:

:label_fin
echo Hasta la vista.