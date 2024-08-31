#include<stdio.h>
#include<string.h>
#include<WinSock2.h>
#include <time.h>
#include "funciones.h"

const char leters[] = {'A', 'E', 'I', 'O', 'U','B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                           'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z',
                           'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                           'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                           '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
                            };


void printClientAddress(SOCKADDR_IN *clientAddr) {
    char ipAddress[16];
    int port = ntohs(clientAddr->sin_port);

    //Convertir ip a string
    strcpy(ipAddress, inet_ntoa(clientAddr->sin_addr));
    printf("Cliente conectado desde IP: %s, Puerto: %d\n", ipAddress, port);
}

void generateUser(char *rta, int size){

    //Verificar longitud valida y enviar mensaje de error
    if(size<5 || size>15){
        strcpy(rta,";");
    }else
    {


    // Elegir si iniciar con vocal o consonante
    int startWithVowel = rand() % 2;

    // Generar el usuario
    for (int i = 0; i < size; i++) {
        if ((i % 2 == 0 && startWithVowel) || (i % 2 != 0 && !startWithVowel)) {
            rta[i] = leters[rand() % 5];
        } else {
            rta[i] = leters[(rand() % 21)+5];
        }
    }
    rta[size] = '\0';
    }

}

void generatePassword(char *rta, int size){
    //Verificar longitud valida y enviar mensaje de error
    if(size<8 || size>49){
        strcpy(rta,";");
    }else
    {
        for(int i = 0; i < size; i++){
            rta[i] = leters[rand() % 62];
        }
    }
}

void convertStringToArray(char* string, int* array){
    // The first character in the string is the first number
    array[0] = string[0] - '0';

    // The rest of the string is the second number
    array[1] = atoi(&string[1]);
}