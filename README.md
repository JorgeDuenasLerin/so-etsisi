# Herramientas de Sistemas Operativos

Este repositorio contiene las herramientas básicas para trabajar en la asignatura de Sistemas Operativos.

## Modificaciones respecto de 2023-2024

Listado de cambios:

- Actualizado QEMU a versión 9
- Los ejecutables son scripts modificables
- Nueva forma de trasferir información.
- En la imagen:
    - Eliminado DHCP de Qemu, configurado red estática en Minix.
    - Eliminada consulta DNS en ssh
    - Instalado unzip en la imagen original.
    - Script de sincronización en la imagen en /bin/syncwin

## Inicio rápido

Para empezar a trabajar con las herramientas, antes de nada hay que añadir la carpeta a las exclusiones del antivirus de windows. Para ello ejecuta desde la terminal el script `utilidades\excluir.bat`. 
Se puede ejecutar de 3 formas diferentes:

1. `excluir.bat`: Excluye tu directorio actual de trabajo
2. `excluir.bat -sd`: Excluye el directorio del script
3. `excluir.bat absolute_path`: Excluye el directorio que le pases ¡Tiene que ser una ruta absoluta!

Una vez excluido, hay que establecer un **identificador** para la imagen y **descomprimir**. Esto solo se hará la primera vez

1. ```echo abcd > id.txt``` (Cuidado con los espacios extra en windows)
2. ```utilidades\descomprimir.bat```

En las siguientes ejecuciones tendremos que:

1. En otra terminal, iniciar el servidor httptar: ```utilidades\httptar.exe```
2. Iniciar qemu con la imagen: ```utilidades\minix.bat```

## Prácticas

Desde windows, el código de las practicas se escribirá en ```trabajo```.

```
trabajo\
 \- bin
 \- prc1
 \- prc2
 \- ...
 \- prcn
```

Desde minix, se puede ejecutar el comand ```syncwin``` (código disponible en ```src```). Este comando:

1. Descarga el contenido de ```trabajo``` y lo dejará en la home del usuario.
2. Hace disponible los scripts en ```bin``` para el usuario actual.
3. Intenta volver al directorio de trabajo.

Si en alguna práctica es necesario hacer alguna tarea de descarga de información o construir algún esquema de directorios se puede automatizar dejando el escript en ```bin```

Ejemplo:

```bin\inicioprc1.sh```

## Tareas en imagen

Esta es la documentación de algunas tareas llevadas a cabo en la imagen original.

> Ya está realizado en la imagen

### Cómo deshabilitar DHCP

```
# cat /etc/hostname.file
minix
# cat /etc/hosts
10.0.2.15 minix
# cat /etc/inet.conf
eth0 dp8390 0 { default: };
# cat /etc/dhcp.conf
host 10.0.2.15/24 {
    DNSServer 10.0.2.3;
    gateway 10.0.2.2;
};
interface ip0 minix:
```

### Deshabilitar DNS en ssh

```
#/usr/local/etc/ssh/sshd_config
...
UseDNS no
```

### syncwin

Hacer llegar el script syncwin a la máquina, coparlo a /bin/, darle permisos 755 y propietario bin

### minixout

Lo mismo para la herramienta minixout

## Curso 24-25

Problemas de permisos al hacer syncwin. Solución:

```
Windows:

git pull

Minix: ($ o  # no se escriben; el primer chmod solo en necesario si el dir trabajo existe en root)

$ su -
# chmod -R u+w trabajo
# syncwin

… salida de syncwin …

# bin/update_tools.sh
Actualizando syncwin en /bin
Actualizando permisos de syncwin
```

Tras estos comando ```syncwin``` verificará que los permisos son correctos.
