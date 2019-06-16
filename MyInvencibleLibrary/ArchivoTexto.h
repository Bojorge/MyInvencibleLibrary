//
// Created by aaron on 15/06/19.
//
#define SERVIDOR_ARCHIVOTEXTO_H

#include <fstream>
#include <iostream>


using namespace std;


class ArchivoTexto {


public:

    void escribir(string texto, string nombreArchivo){
        std::ofstream archivo;

        archivo.open(nombreArchivo,std::ios::out);

        if (archivo.fail()){
            cout<<"No se pudo abrir el archivo"<<endl;
            exit(1);

        }

        archivo<<"\n"<<texto<<"\n";

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
