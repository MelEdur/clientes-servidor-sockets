import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Cliente {
    public static void main(String[] args) throws UnknownHostException, IOException {

        System.out.println("CLIENTE JAVA");
        Scanner scanner = new Scanner(System.in);

        String address = "127.0.0.1";
        int port = 5000;
        Socket socket;

        int option = 0;
        int length = 0;


        while (option != 3) {

            option = Functions.printMenu(scanner);

            switch (option) {
                case 1:
                    //INGRESO LONGITUD
                    System.out.println("Ingrese la longitud del nombre de usuario");
                    length = Functions.readLength(scanner);

                    //REALIZAR REQUEST
                    socket = Functions.send(option, length, scanner,address,port);

                    //RECIBIR RESPUESTA
                    Functions.recieve(socket,5,15);

                    //CERRAR CONEXION
                    socket.close();
                    break;
                case 2:
                    //INGRESO LONGITUD
                    System.out.println("Ingrese la longitud del nombre de la contraseña");
                    length = Functions.readLength(scanner);

                    //REALIZAR REQUEST
                    socket = Functions.send(option, length, scanner,address,port);

                    //RECIBIR RESPUESTA
                    Functions.recieve(socket,8,49);

                    //CERRAR CONEXION
                    socket.close();
                    break;
                case 3:
                    //Cerrar aplicación
                    System.out.println("Saliendo...");
                    break;
                default:

                    System.out.println("Debe ingresar un valod del 1 al 3");
                    break;
            }
        }
    }
}