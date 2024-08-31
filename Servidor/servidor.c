#include<winsock2.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "funciones/funciones.h"

int PUERTO = 5000;

int main(void)
{
    srand((unsigned int)time(NULL));

    SOCKADDR_IN clientAddress;
    int clientAddressSize = sizeof(clientAddress);

    char request[4];
    char rta[256];


    /*Inicializar WinSock en la aplicación Servidor*/
    WSADATA WsaData;
    WSAStartup(MAKEWORD(2,2), &WsaData);

    /*Crear socket para recibir*/
    int serverSocket;
    serverSocket = socket (AF_INET, SOCK_STREAM,0);

    /*Especificamos el puerto en el que se recibirá*/
    struct sockaddr_in serverAddress;
    memset (&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(PUERTO);

    //vinculamos la dirección y el socket creado
    bind (serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    /*Configura la espera de conexiones y cuantas llamadas pueden acumularse*/
    listen (serverSocket, 5);
    printf("Servidor iniciado en IP: %s, Puerto: %d\n",inet_ntoa(serverAddress.sin_addr), PUERTO);
    printf("Esperando conexiones...\n");

    /*Espera la llegada de una conexion*/
    while(1){

        //Aceptar conexion
        SOCKET clientSocket = accept (serverSocket,(SOCKADDR*)&clientAddress, &clientAddressSize);
        printf("----------------------------------------------------\n");
        //Mostrar datos del cliente
        printClientAddress(&clientAddress);

        //RECIBIR DATO
        int Dato[2];
        memset(request, 0, sizeof(request));
        recv(clientSocket,(char*)&request, sizeof(request),0);
        convertStringToArray(request, Dato);


        //Limpiar respuesta
        memset(rta, 0,sizeof(rta));
        switch (Dato[0])
        {
        case 1:
            generateUser(rta, Dato[1]);
            break;
        case 2:
            generatePassword(rta, Dato[1]);
            break;
        default:
            break;
        }

        //Enviar respuesta
        send (clientSocket, rta, strlen(rta),0);
        printf("Dato recibido: %d y %d\n",Dato[0],Dato[1]);
        printf("Dato enviado: %s\n",rta);

        //Desconectar cliente
        closesocket(clientSocket);
        printf("Cliente desconectado, esperando siguiente conexion\n");
    }

    /*Cerrar conexion*/
    closesocket (serverSocket);
    WSACleanup();

    system("pause");
    return 0;
}