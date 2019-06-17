package server;

import BaseDatos.Imagen;
import java.io.*;
import java.net.*;

//Clase que controla la comunicacion con el servidor
//en java y en cliente en C++, por medio de sockets
public class ConeccionC implements Runnable{
	
	
	private static String todo = "";
	private static String imagen = "";

	public ConeccionC() {
		Thread hilo = new Thread(this);
		hilo.start();
	}
	
	public static void main(String[] args) throws IOException{
		new ConeccionC();
	}
	//Funcion que pide a la libreria en formato JSON todos los datos que se encuentran
	//en la base de datos
	static private void verTodo() throws IOException {
		todo = Libreria.obtenerLibreria().verTodo();
		return;
	}
	//Funcion que le pide la libreria los datos de la imagen en JSON
	//ingresando un id, de una imagen en la BAse de Datos
	static private void obtenerImagen(String id) throws IOException{
		imagen = Libreria.obtenerLibreria().obtenerImagen(id);
	}
	//Fuancion que recibe una imagen, y le pide a la libreria que 
	//la almacene en la base de datos
	static private void guardarImagen(Imagen img) throws IOException{
		Libreria.obtenerLibreria().guardarImagen(img);
	}
	//Funcion que recibe una imagen con los datos que se desean cambiar
	//de una imagen con un id igual al ingresado
	static private void renovarImagen(String id, Imagen n) {
		Libreria.obtenerLibreria().renovarImagen(id, n);	
	}
	//Funcion que recibe un id, y le llama a la clase libreria para que 
	//borre la imagen con el mismo id
	static private void borrarImagen(String n) {
		Libreria.obtenerLibreria().borrarImagen(n);
	}
	//Funcion que llama a la clase Libreria para cerrar la coneccion
	static private void cerrarBD() {
		Libreria.obtenerLibreria().cerrarBD();
	}
	@Override
	public void run() {
		int port = 6611;
		try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Servidor esta escuchando en puerto: " + port);
            while(true){
                try{
                    System.out.println("Esperando una coneccion");
                    Socket socket = serverSocket.accept();
                    BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream())); 
                    System.out.println("------Se ha conectado un Cliente-----");
                    String inputLine; 
                    inputLine = in.readLine();
                    if(inputLine == null) {
                    	continue;
                    }
                    boolean confirmacion = false;
                    System.out.println("Cliente dice: " + inputLine);
                    //bUSCAR TODO
                    if (inputLine.startsWith("1") && confirmacion == false) {
                        System.out.println("Cliente Hace comando: " + "1");
                        OutputStream output = socket.getOutputStream();
                        PrintWriter wr = new PrintWriter(output, true);
                        verTodo();
                    	if(todo != null) {
                    		System.out.println("Cliente Pide todos los datos de la BD");
                    		System.out.println("Se envia al Cliente: " + todo);
                    		wr.println(todo);
                    	}
                    	confirmacion = true;
                    wr.close();
                    }//bUSCAR POR ID
                    if (inputLine.startsWith("2")) {
                        System.out.println("Cliente Hace comando: 2... con texto: " + inputLine );
                        OutputStream output = socket.getOutputStream();
                        PrintWriter wr = new PrintWriter(output, true);
                        String id = inputLine.substring(1);
                        obtenerImagen(id);
                		System.out.println("Buscar por id" + id);
                    	System.out.println("Se envia al Cliente: " + imagen);
                    	wr.println(imagen);
                    	wr.close();
                    }//INSERTAR
                    if (inputLine.startsWith("3")) {
                        System.out.println("Cliente Hace comando: 3");
                        OutputStream output = socket.getOutputStream();
                        PrintWriter wr = new PrintWriter(output, true);
                        String insertar = inputLine.substring(1);
                        guardarImagen(Libreria.obtenerLibreria().deserializarImagen(insertar));
                		System.out.println("Cliente inserar imagen: " + insertar);
                    	wr.println("Se agrego correctamente");
                    	wr.close();
                    }//BORRAR
                    if (inputLine.startsWith("4")) {
                        System.out.println("Cliente Hace comando: 4");
                        OutputStream output = socket.getOutputStream();
                        PrintWriter wr = new PrintWriter(output, true);
                        String borrar = inputLine.substring(1);
                        borrarImagen(borrar);
                		System.out.println("Cliente borro imagen: " + borrar);
                    	wr.println("Se Borro correctamente");
                    	wr.close();
                    }//MODIFICAR
                    if (inputLine.startsWith("5")) {
                        System.out.println("Cliente Hace comando: 5");
                        OutputStream output = socket.getOutputStream();
                        PrintWriter wr = new PrintWriter(output, true);
                        String modificar = inputLine.substring(1);
                        String div1 = modificar.substring(0, 2);
                        String imag = inputLine.substring(3);
                        renovarImagen(div1,Libreria.obtenerLibreria().deserializarImagen(imag));
                		System.out.println("Cliente Actualizo imagen con id: " + modificar + "por: " + div1);
                    	wr.println("Se actualizo correctamente");
                    	wr.close();
                    }
                    System.out.println("----Fin de la coneccion----");
                    cerrarBD();
                }catch(Exception e){
                    e.printStackTrace();
                }
            }
      
        } catch (IOException ex) {
            System.out.println("Server exception: " + ex.getMessage());
            ex.printStackTrace();
        }
}

}
	
