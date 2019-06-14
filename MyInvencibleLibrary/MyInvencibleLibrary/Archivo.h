//
// Created by manuel on 24/05/19.
//

#ifndef MYINVENCIBLELIBRARY_ARCHIVO_H
#define MYINVENCIBLELIBRARY_ARCHIVO_H

#include <fstream>
#include <iostream>
#include <cstring>


using namespace std;


class Archivo {


public:

    void crear(string nombre){

        //string formato = ".txt";
        //string nombreArchivo=nombre+".txt";

        //strcpy(nombreArchivo,nombre);
        //strcat(nombreArchivo,formato);

        escribir(nombre, "NULL");

    };

    void escribir(string nombre, string ImageData){
        nombre+=".txt";
        std::ofstream archivo;

        archivo.open(nombre,std::ios::out);

        if (archivo.fail()){
            cout<<"No se pudo abrir el archivo"<<endl;
            exit(1);

        }
        for(int i=0; i< ImageData.length();i++) {
            archivo << ImageData[i];
        }
        archivo.close();

    };

    void leer(string nombreArchivo){

        ifstream archivo;
        string texto;
        //archivo.open("datosServer.txt",ios::in);
        archivo.open(nombreArchivo,ios::in);

        if(archivo.fail()){
            cout<<"No se pudo abrir el archivo";
            exit(1);
        }

        while(!archivo.eof()){// mientras no se haya terminado el archivo
            getline(archivo,texto);
            cout<<texto<<endl;
        }
        archivo.close();

    };



};



#endif //MYINVENCIBLELIBRARY_ARCHIVO_H
