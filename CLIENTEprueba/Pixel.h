//
// Created by manuel on 16/06/19.
//

#ifndef CLIENTEPRUEBA_PIXEL_H
#define CLIENTEPRUEBA_PIXEL_H


#include <cmath>
#include "Imagen.h"

class Pixel {

public:
    int r, g, b;

    Pixel() {
        r=0; g=0; b=0;
    }
    Pixel(int _r, int _g, int _b){
        r = _r; g = _g; b = _b;
    }
    void invertir();

    void posterizar(int niveles);

};




#endif //CLIENTEPRUEBA_PIXEL_H
