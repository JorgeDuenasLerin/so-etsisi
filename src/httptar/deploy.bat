C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd
cl httptar.c /link Ws2_32.lib
copy /Y httptar.exe ..\..\utilidades
del httptar.obj
del httptar.exe