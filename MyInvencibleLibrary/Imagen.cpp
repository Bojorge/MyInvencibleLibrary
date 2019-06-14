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

    Archivo archivo;
    int contador=0;

    for (int i = nombreFichero.length()-5; i > 0; i--) {

        if(nombreFichero[i] == '/'){
            break;
        }else{
            contador+=1;
        }
    }
    char nombreArchivoAUX[contador];
    int contador2=0;
    int s=0;

    for (int i = nombreFichero.length()-5; i > 0; i--) {

        if(nombreFichero[i] == '/'){
            break;
        }else{
            contador2+=1;
            nombreArchivoAUX[s] = nombreFichero[i];
            s+=1;
        }
    }
    //cout << contador;
    char nombreArchivo[contador2];
    for (int i = 0; i < sizeof(nombreArchivoAUX); i++) {
        nombreArchivo[i] = nombreArchivoAUX[contador2-1];
        contador2-=1;
        //cout << " "<<nombreArchivo[i];
    }

    for (int i = 0; i < sizeof(nombreArchivo); i++) {
        cout << " "<<nombreArchivo[i];
    }



    archivo.crear(nombreArchivo);

    cout<<"\n archivo creado"<<endl;

    getline(F, linea);
    if(linea!="P3"){
        cout<<"Formato incorrecto"<<endl;
        return;
    }

    getline(F, linea); // se leen los comentarios
    while(linea[0] == '#'){
        getline(F, linea);
    }
    istringstream S(linea);
    S >> _ancho >> _alto;

    int max;
    F >> max; // maxima intensidad de color entre 0 y 255

    _pixels.resize(_ancho*_alto);
    for(int i=0; i<_pixels.size(); i++){
        F >>  _pixels[i].r;
        F >> _pixels[i].g;
        F >> _pixels[i].b;
    }
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