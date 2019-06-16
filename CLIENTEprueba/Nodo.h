//
// Created by manuel on 16/06/19.
//

#ifndef CLIENTEPRUEBA_NODO_H
#define CLIENTEPRUEBA_NODO_H

#include <clocale>

class Nodo {

public: Nodo* siguiente;
public: int Dato;


    Nodo (int dato){
        Dato = dato;
        siguiente = NULL;
    }
};


#endif //CLIENTEPRUEBA_NODO_H
