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

    void crear(char nombre[]){

        char formato[] = ".txt";
        char nombreArchivo[100];

        strcpy(nombreArchivo,nombre);
        strcat(nombreArchivo,formato);

        escribir(nombreArchivo, 7);



    };

    void escribir(char nombre[], int pixels){
        std::ofstream archivo;

        archivo.open(nombre,std::ios::out);

        if (archivo.fail()){
            cout<<"No se pudo abrir el archivo"<<endl;
            exit(1);

        }

            archivo<<"\n"<<pixels<<"\n";

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
