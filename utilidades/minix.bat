@echo off

@rem Se le puede pasar un /P para forzar
set pregunta=%1

@rem verificamos las herramientas
if exist .\utilidades\qemu\qemu-system-i386w.exe if exist .\imagen\minix3hd.qcow2 goto tools_ok
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
set UTMP=%tmp%\-so-\
mkdir %UTMP%
subst M: %UTMP%
echo M: %UTMP%
subst N: .\
echo N: .\


@rem leeamos su matrícula
set /p ID=<id.txt
set "ID=%ID: =%"
set IMAGE_NAME=minix3hd.%ID%.qcow2
set USB_MINIX_PATH=.\imagen\%IMAGE_NAME%
echo %MINIX_PATH%


@rem Llevamos la imagen a tmp. Si está el flag de preguntar preguntamos antes.
if /I not "%pregunta%"=="/P" goto copy_to_tmp

set /p ANSWER=¿Desea copiar la imagen del USB al directorio de trabajo? (S/N)
if /I "%ANSWER%"=="N" goto no_copy_to_tmp

:copy_to_tmp
echo Copiando imagen de trabajo %USB_MINIX_PATH% a %UTMP% (Accesible en M:)
copy %USB_MINIX_PATH% %UTMP%

:no_copy_to_tmp
set TMP_MINIX_PATH=%UTMP%%IMAGE_NAME%

@rem Verificamos que hay una imagen de trabajo
if exist %TMP_MINIX_PATH% goto working_img_ok
    echo ERROR: No se encuentran la imagen de trabajo en la ruta tmp
    echo %TMP_MINIX_PATH%
    echo Por favor, responde de forma adecuada a la preguntas anteriores.
    goto label_fin_desconectando
:working_img_ok

@rem Copiamos utilidades a %UTMP% si no existe
if not exist %UTMP%\utilidades\ goto copy_utils
    echo Utilidades ya copiadas
    goto :no_copy_utils
:copy_utils
    echo Copiando utilidades a %UTMP%
    mkdir %UTMP%\utilidades\
    xcopy /S .\utilidades\ %UTMP%\utilidades\
:no_copy_utils
echo Utilidades en la localización correcta.



echo Todo bien :)
echo Arrancamos Minix


%UTMP%utilidades\qemu\qemu-system-i386w.exe ^
-cpu "pentium3" ^
-m 512 ^
-rtc base=localtime ^
-hda %TMP_MINIX_PATH% ^
-netdev user,id=n1,ipv6=off,restrict=off,hostfwd=tcp:127.0.0.1:5522-:22 -device ne2k_pci,netdev=n1,mac=52:54:98:76:54:32


@rem Elementos útiles para la configuración de la máquina virtual.
@rem 
@rem Arranca con el CD para instalar
@rem -cdrom .\imagen\minix3_1_2a_ide_build2.iso ^
@rem
@rem Abre la imagen para hacer modificaciones
@rem -hda .\imagen\minix3hd.qcow2 ^
@rem -hda %TMP_MINIX_PATH% ^
@rem
@rem Pruebas
@rem -net nic,model=ne2k_pci -nic user
@rem -netdev user,id=n1,ipv6=off,restrict=off ^
@rem -device ne2k_pci,netdev=n1,mac=52:54:98:76:54:32 
@rem -device ne2k_pci,netdev=net0 ^
@rem -drive format=raw,file=.\disco.img 
@rem -drive file=fat:rw:.\Trabajo,format=raw,media=disk,cache=none
@rem -drive file=fat:rw:.\Trabajo,format=raw,media=disk,cache=none

echo Has finalizado la ejecución de Minix

@rem Preguntar si desea llevar la imagen de vuelta al USB
@rem Traemos la imagen de tmp a usb. Si está el flag de preguntar preguntamos antes.
if /I not "%pregunta%"=="/P" goto copy_to_usb

set /p ANSWER=¿Desea copiar la imagen de trabajo de vuelta al USB? (S/N)
if /I "%ANSWER%"=="N" goto no_copy_to_usb
    
:copy_to_usb
echo Copiando imagen de trabajo %TMP_MINIX_PATH% a %USB_MINIX_PATH%
copy %TMP_MINIX_PATH% %USB_MINIX_PATH%

:no_copy_to_usb


@rem preguntar si desea limpar su imagen del disco del PC
if /I not "%pregunta%"=="/P" goto si_clean

set /p ANSWER=¿Desea limpiar la imagen de trabajo del disco local? (S/N)
if /I "%ANSWER%"=="N" goto no_clean
    

:si_clean
echo Limpiando imagen de trabajo %TMP_MINIX_PATH%
del %TMP_MINIX_PATH%

:no_clean

:label_fin_desconectando
@rem Eliminamos la unidad M: y N:
subst /D M:
subst /D N:

:label_fin
echo Hasta la vista.
