package server;

import java.util.ArrayList;

import BaseDatos.Imagen;

//Clase que comunica el BD Director, la clase 
//coneccionC y la clase RAID
public class Libreria {
	
	private static Libreria INSTANCE = new Libreria();
	private static BDDirector director = new BDDirector();
	private static RAID raid = new RAID();
	
	
	public static Libreria obtenerLibreria() {
		return INSTANCE;
	}
	//Funcion que pide todos los datos que esten en la base de datos
	//a cada uno de los datos, le pide al RAID el valor real de los
	//Datos de cada imagen
	public String verTodo(){
		ArrayList<Imagen> list = director.verTodo();
		for (int i = 0; i < list.size();i++) {
			list.get(i).setDatos(raid.getDato(list.get(i).getId()));;	
		}
		return director.serializador(list);
	}
	//Fucion que pide a la base de datos la imagen con la id indicada
	//despues pide al RAID los datos reales de la imagen
	public String obtenerImagen(String id) {
		Imagen img = director.obtenerImagen(id);
		img.setDatos(raid.getDato(id));
		return serializarImagen(img);
	}
	//Funcion que indica al BDDIrector que guarde una imagen, 
	//antes de guardarla se envian lo datos con la id, al RAID
	//y los datos que se guardan el la BD estan modificados,
	//para reducir el espacion consumido en la BD
	public void guardarImagen(Imagen img) {
		raid.setDato(img.getId(), img.getDatos());
		director.guardarImagen(img);
	}
	public void renovarImagen(String id, Imagen img) {
		director.renovarImagen(id, img);
	}
	public void borrarImagen(String id) {
		director.borrarImagen(id);
	}
	public String serializarImagen(Imagen img) {
		return director.serializarImagen(img);
	}
	public ArrayList<Imagen> deserializador(String str) {
		return director.deserializador(str);
	}
	public Imagen deserializarImagen(String str) {
		return director.deserializarImagen(str);
	}
	public void cerrarBD() {
		director.cerrarBD();
	}
}
