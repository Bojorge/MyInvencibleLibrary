#include <iostream>
#include "Imagen.h"
#include "Archivo.h"
#include "Servidor.h"
#include "Paridad.h"
#include "Disco.h"
#include "RAID_5.h"

//Servidor
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <zconf.h>
#include <sys/types.h>
#include <sys/socket.h>

using namespace std;

int main() {
    //Disco disco;
    //Paridad par;
    //string cod="011-";
    //string a=par.imgTostring("/home/manuel/CLionProjects/MyInvencibleLibrary/Imagenes de prueba/homero.ppm");
    //disco.WRITE(cod.append(a));
    Servidor servidor;
    if(servidor.iniciar()==0){
        sleep(3);
        servidor.reiniciar();
    };
    cout<<"\n *** pasa a la siguiente linea *** \n";
    sleep(3);
    servidor.iniciar();
    //BinDec convertir;
    //convertir.binAdeci(1111);
    //convertir.decAbina(6);

    //Archivo archivo;
    //archivo.crear("nombre del archivo");

    //Imagen I;
    //I.leer("/home/manuel/CLionProjects/MyInvencibleLibrary/Imagenes de prueba/color.ppm");
    //I.leer("/home/manuel/CLionProjects/MyInvencibleLibrary/DISCO1/homero.txt");
    //I.dividir("/home/manuel/CLionProjects/MyInvencibleLibrary/DISCO1/color.txt");
    //I.invertir();
    //I.escribir("/home/manuel/Escritorio/ImagenEscrita.ppm");
    //Imagen T;
    //T = I.cortar(30,80,I.getAncho()-35,I.getAlto()-110);
    //T.escribir("/home/manuel/Escritorio/ImagenCortada.ppm");I
    //Imagen J;
    //J.leer("/home/manuel/Escritorio/color.ppm");
    //J.pegar(T, 100, 100);
    //T.invertir();
    //J.pegar(T, 500, 300);
    //J.posterizar(4);
    //J.escribir("/home/manuel/Escritorio/ImagenPegada.ppm");

}