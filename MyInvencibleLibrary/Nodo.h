//
// Created by manuel on 15/06/19.
//

#ifndef MYINVENCIBLELIBRARY_NODO_H
#define MYINVENCIBLELIBRARY_NODO_H

#include <clocale>

class Nodo {

public: Nodo* siguiente;
public: int Dato;


    Nodo (int dato){
        Dato = dato;
        siguiente = NULL;
    }
};



#endif //MYINVENCIBLELIBRARY_NODO_H
