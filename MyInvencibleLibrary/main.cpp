#include <iostream>
#include "Imagen.h"
#include "RAID_5.h"
#include "Paridad.h"
#include "Disco.h"
#include <fstream>
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "Server.h"
using namespace std;

int main() {
    RAID_5 raid;
    Disco disc;
    Disco dis2;
    vector<string> lisa = {"48", "15", "19", "14"};
    vector<string> lisb = {"76", "124", "43", "94"};
    vector<string> lisc = {"24", "179", "76", "2"};

    vector<string> listalarga = {"48", "15", "19", "14", "76", "124", "43", "94", "24", "179", "76", "2"};
    vector<string> res;
    vector<string> res2;
    string pruebadiv = "p3~#in~800~600~255~19~18~15~17~167~53~83~94~75";

    res = raid.RAID5(lisa, lisb, lisc);
    res2 = raid.RAID5(lisa, lisc, res);
    vector<string> dividida;
    Paridad pasa;

    string cacsfd;
    cacsfd = pasa.convString("gris.ppm");
    cout<<"tama  "<<cacsfd<<endl;

    vector<vector<string>> p1=pasa.dividir(pruebadiv);
    cout << p1.size()<<"   " <<p1[1].size() <<"   "<< p1[2].size()<< endl;
    srand(time(NULL));
    string cod = "005";
    //disc.WRITE(cod.append("-").append(pruebadiv));
    cout<<"dandole"<<endl;
    //cout<<dis2.READ(cod)<<endl;
    //cout<<cacsfd<<endl;

    //I.invertir();
    //I.posterizar(6);
    //I.escribir("ImagenEscrita.ppm");
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
