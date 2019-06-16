package server;
import java.net.*;
import java.io.*;
import java.util.Scanner;
 

import BaseDatos.Imagen;

public class Main {

	/*
	 * 
	 * SIRVE PARA PROBAR SOCKETS 
	 * SERVER <-> SERVER RAID 
	 * 
	 */
	
	public static void inicia() throws IOException {
 
        String hostname = "localhost";
        int port = 8080;
        try (Socket socket = new Socket(hostname, port)) {
 
            OutputStream output = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(output, true);
            String text;
 
            do {
                System.out.println("Mensaje a enviar: ");
                Scanner sc = new Scanner(System.in);
                
                text = sc.nextLine();
                
                InputStream input = socket.getInputStream();
                BufferedReader reader = new BufferedReader(new InputStreamReader(input));
 
                String command = reader.readLine();
                System.out.println("Server sent: " + command);
                
            } while (!text.equals("bye"));
 
            socket.close();
 
        } catch (UnknownHostException ex) {
 
            System.out.println("Server not found: " + ex.getMessage());
 
        } catch (IOException ex) {
 
            System.out.println("I/O error: " + ex.getMessage());
        }
}
	public static void main(String[] args) throws IOException {
		
		RAID raid = new RAID();
		String datos = "p3,#in,800,600,255,12,15,65,15,14,15,14,15,14,17,18,19,19,18,17,15,12,14,14,14";
		Imagen img = new Imagen("002","perro","2014","Pedro","800-900","FOTOdePERROS",datos);
		
		//GET DATO
			System.out.println(raid.getDato(img.getId()));
		
		//SET DATO
			//raid.setDato(img.getId(), img.getDatos());;
		
		//inicia();
	}

}
