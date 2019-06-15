#include <iostream>
#include "Imagen.h"
#include "RAID_5.h"
#include "Paridad.h"
#include <fstream>

using namespace std;
RAID_5 raid;

int main() {
    vector<string> lisa={"48","15","19","14"};
    vector<string> lisb={"76","124","43","94"};
    vector<string> lisc={"24","179","76","2"};

    vector<string> listalarga={"48","15","19","14","76","124","43","94","24","179","76","2"};
    vector<string> res;
    vector<string> res2;
    string pruebadiv="p3,#in,800,600,255,12,15,65,15,14,15,14,15,14,17,18,19,19,18,17,15,12,14,14";

    res=raid.RAID5(lisa,lisb,lisc);
    res2=raid.RAID5(lisa,lisc,res);
    //cout<<res2[0]<<" "<<res2[1]<<" "<<res2[2]<<" "<<res2[3]<<endl;
    vector<string> dividida;
    Paridad pasa;
    string cacsfd;
    cacsfd=pasa.convString("gris.ppm");
    //cout<<"tama  "<<cacsfd<<endl;
    vector<string> p1=pasa.dividir(pruebadiv)[2];
    cout<<raid.vecToString(lisa)<<endl;

    ofstream archivo_salida("/home/aaron/Desktop/MyInvencibleLibrary-Manuel/MyInvencibleLibrary/cmake-build-debug/DISCOVIRTUAL1/tect.txt");
    archivo_salida <<raid.vecToString(lisa);
    archivo_salida.close();
    //cout<<cacsfd<<endl;
    //dividida.data()->erase(0);
    //dividida.data()->erase(0);

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