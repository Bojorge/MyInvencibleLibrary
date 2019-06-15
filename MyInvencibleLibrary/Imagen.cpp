//
// Created by manuel on 05/06/19.
//

#include "string"
#include "Imagen.h"
#include "Pixel.h"
#include "Archivo.h"
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


void Imagen::leer(string nombreFichero){
    ifstream F(nombreFichero.c_str());
    string linea;
    string nombreArchivostr;
    string texto;
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

    archivo.crear(nombreArchivostr);

    cout<<"\n archivo creado"<<endl;

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

    int contador3;
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
    texto+=textoPixels;
    archivo.escribir(nombreArchivostr, texto);
}

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

void Imagen::dividir(string NombreArchivo){
    ifstream F(NombreArchivo.c_str());
    string linea;
    int _alto, _ancho, max;


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
    cout<<_ancho<<"  "<<_alto<<endl;

    F >> max; // maxima intensidad de color entre 0 y 255
    cout<<max<<endl;

    int contador3;
    _pixels.resize(_ancho*_alto);
    for(int i=0; i<_pixels.size(); i++){
        F >> _pixels[i].r;
        F >> _pixels[i].g;
        F >> _pixels[i].b;

        if(i%_ancho == (_ancho-1)){
            cout<<"\n"<<endl;
        }
    }

}
/*ifstream archivo;
string texto;
//archivo.open("datosServer.txt",ios::in);
archivo.open(NombreArchivo,ios::in);

if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
    exit(1);
}
cout<<"ALGO ANDA MAL POR AQUI"<<endl;
cout<<"ALGO ANDA MAL POR AQUI"<<endl;
cout<<"ALGO ANDA MAL POR AQUI"<<endl;
while(!archivo.eof()){// mientras no se haya terminado el archivo
    getline(archivo,texto);


    cout<<texto<<endl;
}
archivo.close();*/

};

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

void Pixel::invertir() {
    r = 255-r;
    g = 255-g;
    b = 255-b;
}


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