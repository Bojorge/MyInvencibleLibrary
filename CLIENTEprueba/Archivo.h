//
// Created by manuel on 16/06/19.
//

#ifndef CLIENTEPRUEBA_ARCHIVO_H
#define CLIENTEPRUEBA_ARCHIVO_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>


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

        archivo.open("/home/manuel/CLionProjects/MyInvencibleLibrary/DISCO1/"+nombre,std::ios::out);

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



#endif //CLIENTEPRUEBA_ARCHIVO_H
