import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class Functions {

    public static int printMenu(Scanner scanner){
        int option = 0;

        while (true) {
            System.out.print("------------------------------\nQue desea hacer?\n1. Generar un usuario.\n2. Generar una contrasenia. \n3. Salir\n>");
            try {
                option = Integer.parseInt(scanner.nextLine());
                break;
            } catch (NumberFormatException e) {
                System.out.println("\033[1;31mDebe ingresar un numero!\033[0m");
            }
        }
        return option;
    }

    public static int readLength(Scanner scanner) {
        int length = 0;

        while (true) {
            try {
                length = Integer.parseInt(scanner.nextLine());
                break;
            } catch (NumberFormatException e) {
                System.out.println("\033[1;31mDebe ingresar un numero!\033[0m");
            }
        }
        return length;
    }

	public static Socket connectToServer(String address, int port,Scanner scanner){

        while (true) {
            try {
                Socket socket = new Socket(address,port);
                return socket;
            } catch (IOException e) {
                System.out.println("\033[1;31mNo se pudo conectar, presione ENTER para reintentar\033[0m");
                scanner.nextLine();
            }
        }
    }

    public static Socket send(int option, int length, Scanner scanner, String address, int port) throws IOException {
        //ARMADO DE DATO
        String dato = String.format("%d%d",option, length);

        //CONEXION AL SERVIDOR
        Socket socket = connectToServer(address,port, scanner);

        //ENVIO DEL DATO
        PrintWriter out = new PrintWriter(socket.getOutputStream());
        out.print(dato);
        out.flush();

        return socket;


    }

    public static void recieve(Socket socket, int min, int max) throws IOException {
        //Leer respuesta
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String rta = in.readLine();

        //Mostrar error o respuesta
        if(rta.charAt(0) == ';'){
            System.out.println("\nRespuesta: \033[1;31mLa longitud debe ser un valor entre "+ min+" y "+max+"\033[0m");
        }else{
            System.out.println("\nRespuesta: \033[32m"+rta+"\033[0m\n");
        }
    }
}
