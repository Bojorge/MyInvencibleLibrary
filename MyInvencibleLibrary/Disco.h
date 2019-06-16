//
// Created by manuel on 24/05/19.
//

#ifndef MYINVENCIBLELIBRARY_DISCO_H
#define MYINVENCIBLELIBRARY_DISCO_H

#include <iostream>
#include "Paridad.h"
#include "RAID_5.h"
#include <fstream>
#include <vector>

using namespace std;

RAID_5 raid;
class Disco {
public:
    string Disco1="/home/aaron/Desktop/MyInvencibleLibrary-Manuel/MyInvencibleLibrary/cmake-build-debug/DISCOVIRTUAL1/";
    string Disco2="/home/aaron/Desktop/MyInvencibleLibrary-Manuel/MyInvencibleLibrary/cmake-build-debug/DISCOVIRTUAL2/";
    string Disco3="/home/aaron/Desktop/MyInvencibleLibrary-Manuel/MyInvencibleLibrary/cmake-build-debug/DISCOVIRTUAL3/";
    string Disco4="/home/aaron/Desktop/MyInvencibleLibrary-Manuel/MyInvencibleLibrary/cmake-build-debug/DISCOVIRTUAL4/";


    void WRITE(string cod_img){
        Paridad pard;

        vector<string> cdyimg=pard.split(cod_img,"-");
        vector<string> v1;
        vector<string> v2;
        vector<string> v3;
        vector<string> v4;

        string img=cdyimg[1];
        string cod=cdyimg[0];
        string vectrs;
        vector<vector<string>> vctrs;
        vector<string> p1=pard.dividir(img)[2];
        pard.split("sdf","s");
        v1=vctrs[0];
        v2=vctrs[1];
        v3=vctrs[2];
        v4=raid.RAID5(v1,v2,v3);




        //convertir cada vector en string y guardarlo en txt en cada disco
    }

    string READ(string codigo){
        Paridad paridad;

        string a;
        //if(Disco1.append(codigo))
        return a;
    }



};


#endif //MYINVENCIBLELIBRARY_DISCO_H
