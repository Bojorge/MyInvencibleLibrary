//
// Created by manuel on 05/06/19.
//

#include "string"
#include "Imagen.h"
#include "Pixel.h"
#include "Archivo.h"
#include "Paridad2.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

Imagen::Imagen()
// llama al constructor por defecto de _pixels
{
    // imagen "vacia"
    _alto=0;
    _ancho=0;
}

Imagen::Imagen(int ancho, int alto)
: _pixels(ancho * alto, Pixel(0, 0, 0))  // le da un tamaño al vector y le da un valor inicial a cada posicion (0=negro)
{
    _ancho = ancho;
    _alto = alto;
}

Imagen::Imagen(const Imagen &other)
        : _pixels(other._pixels)
{
    _alto=other._alto;
    _ancho=other._ancho;
}

/**
* @brief recibe la direccion de la imagen y obtiene los datos de esta
 **/
void Imagen::leer(string nombreFichero){
    ifstream F(nombreFichero.c_str());
    Paridad2 paridad;
    string linea;
    string nombreArchivostr;
    string texto;
    string textoParte1;
    string textoParte2;
    string textoParte3;
    Archivo archivo;
    int contador=0;
    int contador2=0;
    int s=0;
    int max;
    string textoPixels="";
    string cantidadColores="";
    for (int i = nombreFichero.length()-5; i > 0; i--) {

        if(nombreFichero[i] == '/'){
            break;
        }else{
            contador+=1;
        }
    }
    char nombreArchivoAUX[contador];


    for (int i = nombreFichero.length()-5; i > 0; i--) {

        if(nombreFichero[i] == '/'){
            break;
        }else{
            contador2+=1;
            nombreArchivoAUX[s] = nombreFichero[i];
            s+=1;
        }
    }
    char nombreArchivo[contador2];
    for (int i = 0; i < sizeof(nombreArchivoAUX); i++) {
        nombreArchivo[i] = nombreArchivoAUX[contador2-1];
        contador2-=1;
    }

    for (int i = 0; i < sizeof(nombreArchivo); i++) {
        nombreArchivostr+=nombreArchivo[i];
    }

    //archivo.crear(nombreArchivostr);
    //archivo.crear(nombreArchivostr+"Parte1");
    //archivo.crear(nombreArchivostr+"Parte2");
    //archivo.crear(nombreArchivostr+"Parte3");

    //cout<<"\n archivos creados"<<endl;

    getline(F, linea);

    if(linea!="P3"){
        cout<<"Formato incorrecto"<<endl;
        return;
    }
    texto+=linea+"\n";

    getline(F, linea); // se leen los comentarios
    texto+=linea+"\n";
    while(linea[0] == '#'){
        getline(F, linea);
        texto+=linea+"\n";
    }

    istringstream S(linea);
    S >> _ancho >> _alto;


    F >> max; // maxima intensidad de color entre 0 y 255
    texto+=to_string(max)+"\n";

    int division=(_ancho*_alto)/3;
    _pixels.resize(_ancho*_alto);
    for(int i=0; i<_pixels.size(); i++){
        F >> _pixels[i].r;
        F >> _pixels[i].g;
        F >> _pixels[i].b;
        textoPixels+=to_string(_pixels[i].r)+" "+to_string(_pixels[i].g)+" "+to_string(_pixels[i].b)+" ";

        if(i%_ancho == (_ancho-1)){
            textoPixels+="\n";
        }
    }

    //Imagen x;
    //x.escribirApartirDeTexto("/home/manuel/Escritorio/ImagenEscrita.ppm",textoPixels,_ancho, _alto);

    texto+=textoPixels;
    textoParte1=paridad.dividir(textoPixels,1);
    textoParte2=paridad.dividir(textoPixels,2);
    textoParte3=paridad.dividir(textoPixels,3);
    //archivo.escribir(nombreArchivostr, texto);
    //archivo.escribir(nombreArchivostr+"Parte1",textoParte1);
    //archivo.escribir(nombreArchivostr+"Parte2",textoParte2);
    //archivo.escribir(nombreArchivostr+"Parte3",textoParte3);
}


//recibe una direccion para guardar la imagen y la crea
void Imagen::escribir(std::string nombreFichero) const {
    ofstream F(nombreFichero.c_str());
    F << "P3" << endl;
    F << "# escrito para el proyecto 3" << endl;
    F << _ancho << ' ' << _alto << endl;
    F << 255 << endl;

    for(int i=0; i<_pixels.size(); i++){
        F << _pixels[i].r << ' ';
        F << _pixels[i].g << ' ';
        F << _pixels[i].b << ' ';
        if(i%_ancho == (_ancho-1)){
            F << endl;
        }
    }
}

/**
* @brief recibe una direccion para guardar la imagen, un string con los pixeles, el tamaño y la crea
 **/

void Imagen::escribirApartirDeTexto(std::string nombreFichero,std::string pixeles, int _ancho, int _alto) const {
    ofstream F(nombreFichero.c_str());
    F << "P3" << endl;
    F << "# escrito para el proyecto 3" << endl;
    F << _ancho << ' ' << _alto << endl;
    F << 255 << endl;

    for(int s=0;s<pixeles.length()-2;s++){
            F << pixeles[s];
        if(s%_ancho == (_ancho-1)){
            F << endl;
        }
    }



}

/**
* @brief divide la imagen en 3
 **/
void Imagen::dividir(string NombreArchivo){
    ifstream F(NombreArchivo.c_str());
    int V1;
    int V2;
    int V3;
    int max;
    string linea;
    string textoPixeles;
    string texto;
    int _alto, _ancho;


    getline(F, linea);
    cout<<linea<<endl;
    if(linea!="P3"){
        cout<<"Formato incorrecto"<<endl;
        return;
    }


    getline(F, linea); // se leen los comentarios
    cout<<linea<<endl;
    while(linea[0] == '#'){
        getline(F, linea);
        cout<<linea<<endl;
    }

    istringstream S(linea);
    S >> _ancho >> _alto;
    //cout<<_ancho<<"  "<<_alto<<endl;
    V1=_ancho*_alto;
    V2=V1;
    V3=V1;
    vector<int> vector1;
    vector<int> vector2;
    vector<int> vector3;

    F >> max; // maxima intensidad de color entre 0 y 255
    cout<<max<<endl;

    int contador3;
    _pixels.resize(_ancho*_alto);
    for(int i=0; i<_pixels.size(); i++){
        F >> _pixels[i].r;
        F >> _pixels[i].g;
        F >> _pixels[i].b;

        textoPixeles+=to_string(_pixels[i].r)+" "+to_string(_pixels[i].g)+" "+to_string(_pixels[i].b)+" ";
        if(i%_ancho == (_ancho-1)){
            textoPixeles+="\n";
        }


    }
    texto+=textoPixeles;
    cout<<texto;


}

/**
* @brief divide la imagen en 3
 **/
//se indican las dimendiones y se reduce la imagen a ese tamaño
Imagen Imagen::cortar(int izq, int arr, int der, int aba) const {
    Imagen T(der-izq, aba-arr);
    for(int i=izq; i<der; i++){
        for(int j=arr; j<aba; j++){
            if((i >= 0 && i < _ancho) && (j >= 0 && j < _alto)){
                int x = i-izq;
                int y = j-arr;
                T.setPixel(x, y, getPixel(i,j));
            }
        }
    }
    return T;
}

/**
* @brief pega la imagen sobre otra
 **/
void Imagen::pegar(const Imagen& I, int izq, int arr){
    for(int i=0; i<I.getAncho(); i++){
        for(int j=0; j<I.getAlto(); j++){
            int x = izq+i;
            int y = arr+j;
            if((x>=0 && x <= _ancho) && (y>=0 && y <= _alto)){
                setPixel(x, y, I.getPixel(i, j));
            }
        }
    }
}

/**
* @brief invierte los colores
 **/
void Pixel::invertir() {
    r = 255-r;
    g = 255-g;
    b = 255-b;
}

/**
* @brief invierte la imagen
 **/
void Imagen::invertir() {
    for(int i=0; i < _pixels.size(); i++){
        _pixels[i].invertir();
    }
}

int post(int x, int niveles) {
    double valor = double(x) / 255.0*(niveles-1);
    valor = round(valor);
   return int(valor*255.0/(niveles-1));
}

/**
* @brief reduce la cantidad de colores de 255 a "niveles"
 **/
void Pixel::posterizar(int niveles) {
    r = post(r, niveles);
    g = post(g, niveles);
    b = post(b, niveles);
}


void Imagen::posterizar(int niveles) {
    for(int i=0; i < _pixels.size(); i++) {
        _pixels[i].posterizar(niveles);

    }
}