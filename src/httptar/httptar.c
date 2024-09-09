/***
 * httptar.c
 * 
 * Este programa es un servidor que recibe un mensaje por HTTP y envía un archivo comprimido en zip del directorio de trabajo.
 * NOTA: Todo está hardcodeado. Muchas pruebas, mucho tiempo perdido en finales sin salida al trabajar con Minix 312a y Windows.
 * 
 * NoFunciona: Scripts con wget para reproducir una estructura de directorios en Minix. No funciona wget -r ni wget -m.
 * NoFunciona: PowerShell Se solucionó con System.Net.HttpListener pero para escuchar fuera de localhost se necesitan privilegios.
 * NoFunciona: Minix da error de cabecera con tar, solo se ha hecho funcionar la descompresión con unzip.
 * 
 * Programado por: Jorge Dueñas Lerín
 */

/*
    TODO:
    - Reestructurar el código para que sea más modular.
    - Aceptar envío de archivos por POST. (Sincronización Minix-Windows)
    - Añadir un sistema de logs.
    - Añadir parámetro de línea de comandos para cambiar el puerto y la ruta de trabajo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <winsock.h>

#define ZIPPATH "utilidades\\7za.exe"
#define WORKING_PATH ".\\trabajo"
#define WORKING_FILE ".\\trabajo.zip"
#define PORT 8842
#define RCV_BUFFER 4096

// Comprime path_wk en path_file con 7z
int compress7z(char *path_wk, char *path_file) {
    char command[100];
    sprintf(command, "%s a -ttar %s %s", ZIPPATH, path_file, path_wk);
    system(command);
    return 0;
}

// Comprime path_wk en path_file con el comando tar (Da error al descomprimir en la versión de Minix 3.1.2a)
int compress(char *path_wk, char *path_file) {
    char command[100];
    sprintf(command, "tar -a -c -f %s %s", path_file, path_wk);
    system(command);
    return 0;
}

// Borra fichero en path
int deleteFile(char *path) {
    if (remove(path) == 0) {
        return 0;
    } else {
        return 1;
    }
}

// Escribe en el socket el fichero WORKING_FILE con el protocolo HTTP escrito a fuego en el código
int sendFile(SOCKET new_socket) {
    FILE *file;
    char buffer[RCV_BUFFER];
    int read;

    file = fopen(WORKING_FILE, "rb");
    if (file == NULL) {
        printf("Error al abrir archivo.\n");
        return 1;
    }

    // Cabecera y fichero
    char header[255];
    sprintf(header, "HTTP/1.0 200 OK\nContent-Type: application/octet-stream\nContent-Disposition: attachment; filename=\"%s\"\n\n", WORKING_FILE);
    send(new_socket, header, strlen(header), 0);

    while ((read = fread(buffer, 1, RCV_BUFFER, file)) > 0) {
        if (send(new_socket, buffer, read, 0) < 0) {
            printf("Error al enviar archivo.\n");
            printf("%d\n", WSAGetLastError());
            return 1;
        }
    }

    fclose(file);
    return 0;
}

// Abre socket TCP windows y recibe mensaje HTTP, comprime WORKING_PATH y envía WORKING_FILE. ¡Todo en Uno!
int openServer() {
    WSADATA wsaData;
    SOCKET s;
    struct sockaddr_in server, client;
    int c;
    char buffer[RCV_BUFFER];

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Error al inicializar Winsock.\n");
        return 1;
    }

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        printf("Error al crear socket.\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(s, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
        printf("Error al hacer bind.\n");
        return 1;
    }

    listen(s, 3);

    printf("Esperando conexiones...\n");

    c = sizeof(struct sockaddr_in);
    SOCKET new_socket = accept(s, (struct sockaddr *) &client, &c);
    if (new_socket == INVALID_SOCKET) {
        printf("Error al aceptar conexión.\n");
        return 1;
    }

    printf("Conexión aceptada.\n");

    recv(new_socket, buffer, RCV_BUFFER, 0);
    //printf("Mensaje recibido: %s\n", buffer);

    compress(WORKING_PATH, WORKING_FILE);
    sendFile(new_socket);
    deleteFile(WORKING_FILE);

    closesocket(new_socket);
    closesocket(s);
    WSACleanup();

    return 0;
}

int main() {
    printf("Arrancado server!\n");
    while(1){
        openServer();
    }
    return 0;
}
