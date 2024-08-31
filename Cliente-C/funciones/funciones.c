#include <stdio.h>
#include <WinSock2.h>
#include "funciones.h"

void printMenu(int *option) {
     int result = 0;
     char ch;

     while (result != 1)
     {
        printf("------------------------------\nQue desea hacer?\n1. Generar un usuario.\n2. Generar una contrasenia. \n3. Salir\n>");
        fflush(stdin);
        result = scanf("%d",option);
        if(result != 1){
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("\033[1;31mDebe ingresar un numero!\033[0m\n");
        }
     }
}

void readLength(int *length){
    int result = 0;
    char ch;
    while (result != 1){
        //printf("Ingrese la longitud del nombre de usuario\n");
        fflush(stdin);
        result = scanf("%d",length);
        if(result != 1){
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("\n\033[1;31mDebe ingresar un numero!\033[0m\n");
        }
    }
}

void connectToServer(SOCKET Sock, struct sockaddr_in *serverAddress){

    int iResult = connect(Sock, (SOCKADDR *)serverAddress, sizeof(*serverAddress));
    while (iResult != 0)
    {
        printf("\n\033[1;31mNo se pudo conectar, presione cualquier tecla para reintentar\033[0m\n");
        system("pause > nul");
        iResult = connect(Sock, (SOCKADDR *)&serverAddress, sizeof(serverAddress));
    }
}

void sendData(int option, int length, SOCKET Sock, struct sockaddr_in *serverAddress){
    //ARMADO DE DATO
    char dato[4];
    sprintf(dato, "%d%d",option, length);
    //CONEXION
    connectToServer(Sock, serverAddress);
    //ENVIO DEL DATO
    send(Sock, dato, sizeof(dato),0);

}
void recieve(SOCKET Sock, int min, int max){
    char rta[80];
    memset(rta,0,sizeof(rta));

    recv(Sock, (char*)&rta, sizeof(rta),0);
    if(rta[0] == ';'){
                printf("\nRespuesta: \033[1;31mLa longitud debe ser un valor entre %d y %d\033[0m\n",min,max);
            }else
            {
                printf("\nRespuesta: \033[32m%s\033[0m\n",rta);
            }


}