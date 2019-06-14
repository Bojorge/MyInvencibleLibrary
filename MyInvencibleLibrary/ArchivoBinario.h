//
// Created by manuel on 12/06/19.
//

#ifndef MYINVENCIBLELIBRARY_ARCHIVOBINARIO_H
#define MYINVENCIBLELIBRARY_ARCHIVOBINARIO_H

#include <cstdio>
#include <fstream>
#include <iostream>

class ArchivoBinario {

    struct Objeto{
        int Xposicion;
        int Yposicion;
        char letra[256];
    };



public:

    int escribirArchivoBinario(char nombreArchivo[],int cantidadLetras, Objeto letras[]){
        FILE *archivo = fopen(nombreArchivo, "wb");

        if (archivo == NULL){
            fprintf(stderr, "Error: No se puede abrir el archivo\n");
            return -1;
        }

        for (int x = 0; x < cantidadLetras; ++x){
            fwrite(&letras[x], sizeof(Objeto), 1, archivo);
        }
        fclose(archivo);

        return 0;

    };


    void crearArchivoBinaro(){

        Objeto letras[] = {
                {10, 20,'l'},
                {30, 40,'k'},
                {50, 60,'i'},
                {70, 80,'j'},
        };

        const int cantidadLetras = sizeof(letras)/ sizeof(Objeto);
        Objeto lecturaInformacion[cantidadLetras];
        char nombreArchivo[] = "Serializado.txt";

        escribirArchivoBinario(nombreArchivo, cantidadLetras, letras);
        leerArchivoBinario(nombreArchivo, cantidadLetras);


    };

    int leerArchivoBinario(char nombreArchivo[], int cantidadLetras){


        Objeto lecturaInformacion[cantidadLetras];
        FILE *archivo = fopen(nombreArchivo, "rb");

        if (archivo == NULL){
            fprintf(stderr, "Error: No se puede abrir el archivo\n");
            return  -2;
        }

        for (int x = 0; x < cantidadLetras; ++x){
            fread(&lecturaInformacion[x], sizeof(Objeto), 1, archivo);
        }

        fclose(archivo);

        for (int x = 0; x < cantidadLetras; ++x) {
            printf("La posicion en X es: %d\n", lecturaInformacion[x].Xposicion);
            printf("La posicion en Y es: %d\n", lecturaInformacion[x].Yposicion);
            printf("La letra es: %s\n", lecturaInformacion[x].letra);
            printf("\n");
        }
        printf("\n");
        return  0;

    }

};


#endif //MYINVENCIBLELIBRARY_ARCHIVOBINARIO_H
