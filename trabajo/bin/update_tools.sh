#!/bin/sh

# Guardamos el directorio actual para volver a él al final
wd=$(pwd)
cd

echo "Actualizando syncwin en /bin"
cp trabajo/bin/syncwin /bin 

echo "Actualizando permisos de syncwin"
chown bin /bin/syncwin
chmod 755 /bin/syncwin

cd $wd
