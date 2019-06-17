package server;

import java.util.ArrayList;
import BaseDatos.*;

// Clase que controla la comunicacion entre el JAR BaseDATOSDIY
// y el proyecto del serverLibrarySocket
public class BDDirector {

	BDCliente cliente;
	BD bd;
	static BDColeccion coleccion;
	
	public BDDirector() {
	try {
		cliente = new BDCliente("localhost",27017);
		bd = cliente.getBD("Geleria");
		coleccion = bd.getColeccion("Imagenes");
	}catch(Exception e) {
		System.out.println("Error al conectar con base de datos");
	}
	}
	public ArrayList<Imagen> verTodo(){
		ArrayList<Imagen> list = new ArrayList<Imagen>();
		BDCursor cursor = coleccion.find();
		for (int i = 0; i < cursor.tamano();i++) {
			list.add(cursor.get(i));	
		}
		cursor.cerrar();
		return list;
	}
	
	//Funcion que por medio de una id, le pide a la base de datos
	//que retorne una imagen con la misma id
	public Imagen obtenerImagen(String id) {
		Imagen img= coleccion.find("id",id);
		return img;	
	}
	//Funcion que le indica a la base de datos que guarde una imgen
	//con lo datos ingresados
	public void guardarImagen(Imagen img) {
		img.setDatos("0001001");
		coleccion.insert(img);
	}
	//Funcion que sustituye los datos de una imagen con un id espe-
	//cifico, por uno ingresados, en la base de datos
	public void renovarImagen(String id, Imagen img) {
		Imagen buscar = coleccion.buscar("id",id);
		coleccion.actualizar(buscar, img);
	}
	//Funcion que le pide a la base de datos que elimine una imagen 
	//con un id indicado
	public void borrarImagen(String id) {
		Imagen buscarYBorar = coleccion.buscar("id", id);
		coleccion.encontrarYBorrar(buscarYBorar);
	}
	//Fucion que deserializa un archivo en formato JSON
	//Lo convierte a un a lista de imagenes
	public ArrayList<Imagen> deserializador(String json) {
		ArrayList<Imagen> coleccion2 = new ArrayList<Imagen>();
		String id = ""; String pe = "";String dato = "";
		String ano = ""; String autor = ""; String des = "";
		String nom = "";
		String[] accion = json.split(";");
		int cont = 1;
		for(int i = 0; i < accion.length; i++) {
			String r = accion[i];
			String[] imagen = r.split(",");
			for(int j = 0; j < imagen.length;j++ ){
				String h = imagen[j];
				String[] parte = h.split(" ");
				if(cont == 1){id = parte[1];}
				if(cont == 2){nom = parte[1];}
				if(cont == 3){ano = parte[1];}
				if(cont == 4){autor = parte[1];}
				if(cont == 5){pe = parte[1];}
				if(cont == 6){des = parte[1];}
				if(cont == 7){dato = parte[1];}
				cont++;
				}
			Imagen g = new Imagen(id,nom,ano,autor,pe,des,dato);
			coleccion2.add(g);
			cont = 1;
		}
		return coleccion2;
	}
	//Funcion qye dada una lista de imagenes, convierte los datos en ella
	//por un string en formato JSON
	public String serializador(ArrayList<Imagen> list) {
		String TodasImagenes = "";
		ArrayList<Imagen> lista1 = list;
		for ( int i = 0; i < (lista1.size()-1); i++) {
			TodasImagenes = TodasImagenes + serializarImagen(lista1.get(i))+ ";" ;
		}
		TodasImagenes = TodasImagenes + serializarImagen(lista1.get(lista1.size()-1));		
		return TodasImagenes;
	}
	//funcion que serializa en formato JSON un objeto de tipo imagen
	public String serializarImagen(Imagen img) {
		String string = 
				"{\"id\": "  + img.getId() + "," +
				"\"Nombre\": " + img.getNombre() + "," +
				"\"ano\": " + img.getAno() + "," +
				"\"autor\": " + img.getAutor() + "," +
				"\"tamano\": " + img.getPeso() + "," +
				"\"Descripcion\": " + img.getDescripcion() + "," +
				"\"datos\": " + img.getDatos() + " }";
		return string;
	}
	//Funcion dado un string en formato JSON, retorna una imagen
	public Imagen deserializarImagen(String str) {
		String id = ""; String pe = "";String dato = "";
		String ano = ""; String autor = "";String des = "";
		String nom = "";
		int cont = 1;
		String[] imagen = str.split(",");
		for(int j = 0; j < imagen.length;j++ ){
			String h = imagen[j];
			String[] parte = h.split(" ");
			if(cont == 1){id = parte[1];}
			if(cont == 2){nom = parte[1];}
			if(cont == 3){ano = parte[1];}
			if(cont == 4){autor = parte[1];}
			if(cont == 5){pe = parte[1];}
			if(cont == 6){des = parte[1];}
			if(cont == 7){dato = parte[1];}
			cont++;
			}
		Imagen g = new Imagen(id,nom,ano,autor,pe,des,dato);
		return g;
	}
	//Funcion que cierra la base de datos y la coneccion con esta
	public void cerrarBD() {
		coleccion.cerrarBD();
	}
	
	
	
}
