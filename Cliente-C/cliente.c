#include<WinSock2.h>
#include<stdio.h>
#include<windows.h>
#include "funciones/funciones.h"

int PUERTO = 5000;

void main(void)
{
    int option = 0;
    int length = 0;

    /* Inicializar WinSock en la aplicación Cliente */
    WSADATA WsaData;
    WSAStartup(MAKEWORD(2, 2), &WsaData);

    /*Crear socket*/
    SOCKET Sock;

    /*Configurar a donde intentará conectarse el cliente*/
    SOCKADDR_IN serverAddress;
    memset (&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(PUERTO);

    printf("CLIENTE C\n");
    //Menu
    while(option != 3){

        Sock = socket (AF_INET, SOCK_STREAM, 0);

        printMenu(&option);

        switch (option)
        {
        case 1:
            //INGRESO LONGITUD
            printf("Ingrese la longitud del nombre de usuario: ");
            readLength(&length);

            //ENVIAR REQUEST
            sendData(option, length,Sock, &serverAddress);

            //RECIBIR RESPUESTA
            recieve(Sock,5,15);

            //CERRAR CONEXION
            closesocket(Sock);
            break;
        case 2:
            //INGRESO LONGITUD
            printf("Ingrese la longitud de la contrasenia: ");
            readLength(&length);

            //ENVIAR REQUEST
            sendData(option, length,Sock, &serverAddress);

            //RECIBIR RESPUESTA
            recieve(Sock,8,49);

            //CERRAR CONEXION
            closesocket(Sock);
            break;
        case 3:
            printf("Saliendo...\n");
             /*Cerrar conexion*/
            closesocket(Sock);
            WSACleanup();

            Sleep(1000);
            return;
            break;
        default:
            printf("\033[1;31mDebe ingresar un valor del 1 al 3\033[0m\n");
            break;
        }

    }
}