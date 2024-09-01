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

Para comenzar a trabajar con las herramientas hay que establecer un **identificador** para la imagen y **descomprimir**. Esto solo se hará la primera vez

1. ```echo "abcd" > id.txt```
2. ```utilidades\descomprimir.bat```

En las siguientes ejecuciones tendremos que:

1. Iniciar el servidor httptar: ```utilidades\httptar.exe```
2. Iniciar qemu con la imagen: ```utilidades\minix.bat```



## Tareas en imagen

### Cómo deshabilitar DHCP

> Ya está realizado en la imagen

```
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
UseDNS no
```