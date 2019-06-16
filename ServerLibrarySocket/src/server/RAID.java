package server;

import java.net.*;
import java.io.*;
public class RAID {
	
	private Socket clientSocket;
    private PrintWriter out;
    private BufferedReader in;
    private String ip = "192.168.0.9";
    private int port = 8080;
    
    
	public String getDato(String id){
		String h = "010001011";
		try {h = getDatoRAID(id);}
		catch(IOException e) {}
		return h;
	}
	
	public void setDato(String id,String dato){
		String enviar = id + "-"+ dato;
		try {setDatoRAID(enviar);}
		catch(IOException  e){}
		return;
	}
	private String getDatoRAID(String id) throws IOException {
		startConnection(ip,port);
		String data = sendMessage(id);
		stopConnection();
		return data;	
	}
	private void setDatoRAID(String enviar) throws IOException {
		startConnection(ip,port);
		sendMessage(enviar);
		stopConnection();	
	}
	
    private void startConnection(String ip1, int port1) throws IOException {
        clientSocket = new Socket(ip1, port1);
        out = new PrintWriter(clientSocket.getOutputStream(), true);
        System.out.println("se conecto");
        in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
    }
 
    private String sendMessage(String msg) throws IOException {
    	String xd = GenerarString(100);
        out.println("001");
        String resp = in.readLine();
        return resp;
    }
 
    private void stopConnection() throws IOException {
        in.close();
        out.close();
        clientSocket.close();
    }
    
    private String GenerarString(int tamano) {
    	String xd = "";
    	for(int i = 0; i <tamano ; i++) {
    		xd= xd + "A";
    	}
    	System.out.println("Tamano del string: "+ xd.length());
    	return xd;
    }
	
	
}
