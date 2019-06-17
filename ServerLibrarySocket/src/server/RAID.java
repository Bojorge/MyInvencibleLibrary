package server;

import java.net.*;
import java.io.*;

//Clase que comunica el ServidorLibrary con el servidor RAID
public class RAID {
	
	private Socket clientSocket;
    private PrintWriter out;
    private BufferedReader in;
    private String ip = "192.168.0.9";
    private int port = 8085;
    
    //FUncion que retorna el dato de una imagen con un id
    //indicado
	public String getDato(String id){
		String h = "010001011";
		//id = "\""+id+"\"";
		try {h = getDatoRAID(id);
		if(h == null) {h="Me Cago en Blen :)";}}
		catch(IOException e) {}
		return h;
	}
	//Funcion que guarda los datos de una imagen con un id 
	//indicado
	public void setDato(String id,String dato){
		String enviar = id + "-"+ dato;
		try {setDatoRAID(enviar);}
		catch(IOException  e){}
		return;
	}
	//Funcion que llama al RAID para perdir los datos
	private String getDatoRAID(String id) throws IOException {
		startConnection(ip,port);
		String data = sendMessage(id);
		stopConnection();
		return data;	
	}
	//Funcion que llama al RAID para guardar los datos
	private void setDatoRAID(String enviar) throws IOException {
		startConnection(ip,port);
		sendMessage(enviar);
		stopConnection();	
	}
	//Funcion que inicia una coneccion por sockets
    private void startConnection(String ip1, int port1) throws IOException {
        clientSocket = new Socket(ip1, port1);
        out = new PrintWriter(clientSocket.getOutputStream(), true);
        System.out.println("se conecto");
        in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
    }
    //Funcion que envia un mensaje por medio de sockets
    private String sendMessage(String msg) throws IOException {
        out.println(msg);
        String resp = in.readLine();
        return resp;
    }
    //Funcion que cierra la coneccion de los sockets
    private void stopConnection() throws IOException {
        in.close();
        out.close();
        clientSocket.close();
    }
}
