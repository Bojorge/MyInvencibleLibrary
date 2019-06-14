//
// Created by manuel on 12/06/19.
//

#ifndef MYINVENCIBLELIBRARY_PIXEL_H
#define MYINVENCIBLELIBRARY_PIXEL_H

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


#endif //MYINVENCIBLELIBRARY_PIXEL_H
