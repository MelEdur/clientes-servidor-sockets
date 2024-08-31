#ifndef FUNCIONES_SERVER
#define FUNCIONES_SERVER

#include <winsock2.h>

// Mostrar cliente conectado
void printClientAddress(SOCKADDR_IN *clientAddr);

//Genera nombre de usuario en base a la longitud ingresada
void generateUser(char *rta, int size);

//Genera contraseña en base a la longitud ingresada
void generatePassword(char *rta, int size);

void convertStringToArray(char* string, int* array);

#endif