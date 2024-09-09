# httptar

Abre un socket TCP por el que da respuestas HTTP con un zip del directorio trabajo.

## Compilación

Con Visual Studio Community instalado:

1. Carga las rutas para compilación manual:
    - "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd"
    - "C:\Program Files\Microsoft Visual Studio\xxxx\Community\Common7\Tools\vsdevcmd"
2. Compila con WinSock:
    - cl httptar.c /link Ws2_32.lib
3. Copia el ejecutable al destino;
    - copy /Y httptar.exe ..\..\utilidades
4. Limpia:
    - del httptar.obj
    - del httptar.exe