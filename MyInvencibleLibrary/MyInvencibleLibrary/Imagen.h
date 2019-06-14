//
// Created by manuel on 05/06/19.
//

#ifndef MYINVENCIBLELIBRARY_IMAGEN_H
#define MYINVENCIBLELIBRARY_IMAGEN_H

#include "string"
#include "Pixel.h"
#include <vector>


/*struct Pixel {
    int r, g, b;


    Pixel() {
        r=0; g=0; b=0;
    }
    Pixel(int _r, int _g, int _b){
        r = _r; g = _g; b = _b;
    }
    void invertir();
    void posterizar(int niveles);
};*/

class Imagen {
    //std::vector<int> _pixels;
    std::vector<Pixel> _pixels;
    int _ancho, _alto;
public:
    Imagen();
    Imagen(int ancho, int alto);
    Imagen(const Imagen& other);

    int getAncho() const {return _ancho;}
    int getAlto() const {return _alto;}

    Pixel getPixel(int i, int j) const {
        return _pixels[j*_ancho+i];
    }

    void setPixel(int i, int j, Pixel valor){
        _pixels[j*_ancho+i]=valor;
    }
    std::string leerPixeles(std::string nombreFichero);
    void leer(std::string nombreFichero);    /////////////////

    void escribir(std::string nombreFichero) const;

    Imagen cortar(int izq, int arr, int der, int aba) const;

    void pegar(const Imagen& I, int izq, int arr);

    void invertir();

    void posterizar(int niveles);

};


#endif //MYINVENCIBLELIBRARY_IMAGEN_H
