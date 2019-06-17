//
//

#ifndef MYINVENCIBLELIBRARY_ARCHIVOBINARIO_H
#define MYINVENCIBLELIBRARY_ARCHIVOBINARIO_H

#include <cstdio>
#include <fstream>
#include <iostream>

//clase que crea el archivo binario

class ArchivoBinario {

    struct Objeto{
        int Xposicion;
        int Yposicion;
        char letra[256];
    };



public:
    //metodo que escribe un archivo binario que recibe como entrada el nombre del archivo, la cant de letras y el objeto letras
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

    //metodo tipo void que crea el archivo binario
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
    //metodo que retorna int que se encaraga de leer el archivo binario y recibe como parametros el nombre del archivo y la cant de letras
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
