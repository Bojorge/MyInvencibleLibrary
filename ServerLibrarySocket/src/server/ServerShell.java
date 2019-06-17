package server;

import java.io.IOException;
import java.util.Scanner;
import BaseDatos.Imagen;

public class ServerShell{

	public static Scanner scan = new Scanner(System.in);
	private static String todo = "";
	private static String imagen = "";
	
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
	
	public static void run() throws IOException {
		try {
		System.out.println("---------------BD Shell------------");
		String str = scan.nextLine();
		String[] comand = str.split(" ");
		if (comand[0].equals("SELECT")) {
				String findTodo = scan.nextLine();
				String[] donde = findTodo.split(" ");
				String where = scan.nextLine();
				String[] condi = where.split(" ");
				System.out.println("Buscando en Colecion: " + donde[1] + ", Condicion: " + condi[1]);
				if(comand[1].equals("*")){
					if (condi[1].equals("*")) {
						verTodo();
						System.out.println(todo);
					}else {
						obtenerImagen(condi[1]);
						System.out.println(imagen);
					}	
				}if(comand[1].equals("NOMBRE")){
						obtenerImagen(condi[1]);
						Imagen img = Libreria.obtenerLibreria().deserializarImagen(imagen);
						System.out.println(img.getNombre());
				}if(comand[1].equals("DESCRIPCION")){
						obtenerImagen(condi[1]);
						Imagen img = Libreria.obtenerLibreria().deserializarImagen(imagen);
						System.out.println(img.getDescripcion());
				}if(comand[1].equals("AUTOR")){
					obtenerImagen(condi[1]);
					Imagen img = Libreria.obtenerLibreria().deserializarImagen(imagen);
					System.out.println(img.getAutor());
				}
		}if (str.equals("INSERT")) {
			String into = scan.nextLine();
			String[] donde = into.split(" ");
			System.out.println("VALUES ID,NOMBRE,ANO,AUTOR,TAMANO,DESCRIPCION,DATOS");
			String values = scan.nextLine();
			String[] condi = values.split(" ");
			String[] tv = condi[1].split(",");
			if (tv.length == 7) {
				System.out.println("Agregando a colecion " + donde[1] + ", Atributos: " + condi[1]);
				Imagen img = new Imagen(tv[0],tv[1],tv[2],tv[3],tv[4],tv[5],tv[6]);
				guardarImagen(img);
			}else {
				System.out.println("Error con cantidad de Values");
			}
			
		}if (comand[0].equals("DELETE")) {
			String from = scan.nextLine();
			String[] donde = from.split(" ");
			String where = scan.nextLine();
			String[] condi = where.split(" ");
			System.out.println("Borrando de Colecion: " + donde[1] + ", Condicion: " + condi[1]);
			borrarImagen(condi[1]);
			
		}if (comand[0].equals("UPDATE")) {
			String set = scan.nextLine();
			String[] donde = set.split(" ");
			String[] values = donde[1].split(",");
			String where = scan.nextLine();
			String[] condi = where.split(" ");
			if (values.length == 7) {
				System.out.println("Actualizando de coleccion: " + comand[1] + ", condicion " + condi[1]+ ", POR: "+ donde[1]);
				String six = values[5];
				if(six == "N") {six = "";}
				Imagen img = new Imagen(values[0],values[1],values[2],values[3],values[4],values[5],six);
				renovarImagen(condi[1],img);
			}else {
				System.out.println("Error con cantidad de Values");

			}
			
		}if (comand[0].equals("CLOSE")) {
			cerrarBD();
			return;
		}
		}catch(IOException e) {
			
		}
		cerrarBD();
		run();
	}

	public static void main(String[] args) throws IOException {
		run();
	}
}
