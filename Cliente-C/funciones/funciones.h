#ifndef FUNCIONES_CLIENTE
#define FUNCIONES_CLIENTE

//Muestra menu y lee opcion
void printMenu(int *option);

//Lee longitud a enviar
void readLength(int *length);

//Conectar
void connectToServer(SOCKET Sock, struct sockaddr_in *serverAddress);

//Enviar paquete
void sendData(int option, int length, SOCKET Sock, struct sockaddr_in *serverAddress);

//Recibir respuesta
void recieve(SOCKET Sock, int min, int max);
#endif