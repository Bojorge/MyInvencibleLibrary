//
// Created by manuel on 24/05/19.
//

#ifndef MYINVENCIBLELIBRARY_DISCO_H
#define MYINVENCIBLELIBRARY_DISCO_H

#include "Paridad.h"
#include "RAID_5.h"
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <fstream>
using namespace std;

class Disco {
public:
    string Disco1="/home/aaron/Desktop/MyInvencibleLibrary-Manuel/MyInvencibleLibrary/cmake-build-debug/DISCOVIRTUAL1/";
    string Disco2="/home/aaron/Desktop/MyInvencibleLibrary-Manuel/MyInvencibleLibrary/cmake-build-debug/DISCOVIRTUAL2/";
    string Disco3="/home/aaron/Desktop/MyInvencibleLibrary-Manuel/MyInvencibleLibrary/cmake-build-debug/DISCOVIRTUAL3/";
    string Disco4="/home/aaron/Desktop/MyInvencibleLibrary-Manuel/MyInvencibleLibrary/cmake-build-debug/DISCOVIRTUAL4/";
    RAID_5 raid;
    Paridad pard;

    void WRITE(string cod_img){
        vector<string> cdyimg=pard.split(cod_img,"-");
        vector<string> v1;
        vector<string> v2;
        vector<string> v3;
        vector<string> v4;

        string img=cdyimg[1];
        string cod=cdyimg[0];
        string vectrs;
        vector<vector<string>> vctrs;
        vctrs=pard.dividir(img);
        v1=vctrs[0];
        v2=vctrs[1];
        v3=vctrs[2];
        v1.pop_back();
        v1.pop_back();
        string tx=v1[v1.size()];
        string ty=v1[v1.size()+1];
        v4=raid.RAID5(v1,v2,v3);
        v1.push_back(tx);
        v1.push_back(ty);
        v4.push_back(tx);
        v4.push_back(ty);

        srand(time(NULL));

        int Discorand=0 + rand() % (3 +1 - 0) ;
        int vect=0;
        while(vect<4){
            vector<string> guardar;
            if(vect==0){
                guardar=v1;
            }
            if(vect==1){
                guardar=v2;
            }
            if(vect==2){
                guardar=v3;
            }
            if(vect==3){
                guardar=v4;
            }
            if(Discorand==0){  //si el disco a guardar es el 0
                string codigo=cod;
                codigo=codigo.append(to_string(vect));
                string ruta=Disco1.append(codigo);
                ofstream archivo1(ruta.append(".txt"));
                archivo1<<raid.vecToString(guardar);
                archivo1.close();
                vect++;
                Discorand++;
                continue;
            }
            if(Discorand==1){
                string codigo=cod;
                codigo=codigo.append(to_string(vect));
                string ruta=Disco2.append(codigo);
                ofstream archivo2(ruta.append(".txt"));
                archivo2<<raid.vecToString(guardar);
                archivo2.close();
                vect++;
                Discorand++;
                continue;
            }
            if(Discorand==2){
                string codigo=cod;
                codigo=codigo.append(to_string(vect));
                string ruta=Disco3.append(codigo);
                ofstream archivo3(ruta.append(".txt"));
                archivo3<<raid.vecToString(guardar);
                archivo3.close();
                vect++;
                Discorand++;
                continue;
            }
            if(Discorand==3){
                string codigo=cod;
                codigo=codigo.append(to_string(vect));
                string ruta=Disco4.append(codigo);
                ofstream archivo4(ruta.append(".txt"));
                archivo4<<raid.vecToString(guardar);
                archivo4.close();
                vect++;
                Discorand=0;
                continue;
            }
        }
        return;
        //convertir cada vector en string y guardarlo en txt en cada disco
    }

    string READ(string codigo){
        string parteS1="";
        string parteS2="";
        string parteS3="";
        string parteS4="";
        string tx;
        string ty;

        //Se agrega
        string archivo1=Disco1.append(codigo);
        string archivo2=Disco2.append(codigo);
        string archivo3=Disco3.append(codigo);
        string archivop=Disco4.append(codigo);

        //Buscar la primera parte en todos los discos
        string parte=archivo1;
        int contDico=0;
        int contArch=0;
        int contbusq=0;
        while(contArch<4){
            string guardar="";
            if(contDico==0){
                guardar=archivo1;
            }
            if(contDico==1){
                guardar=archivo2;
            }
            if(contDico==2){
                guardar=archivo3;
            }
            if(contDico==3){
                guardar=archivop;
            }

            if(contArch==0){
                if(contbusq==4){
                    contbusq=0;
                    contDico=0;
                    contArch++;
                    continue;
                }
                //cout<<"buscando archivo 1"<<endl;
                string strtemp=guardar;
                ifstream fe1(strtemp.append(to_string(contArch).append(".txt")));
                strtemp="";
                if(fe1.good()) {
                    fe1>>parteS1;
                    vector<string> p1st=paridad.split(parteS1,"~");
                    tx=p1st[p1st.size()-2];
                    //p1st.pop_back();
                    ty=p1st[p1st.size()-1];
                    p1st.pop_back();
                    p1st.pop_back();
                    parteS1=paridad.vecToString(p1st);
                    fe1.close();
                    contDico=0;
                    contArch++;
                    contbusq=0;
                    //cout<<"se encontro archivo"<<endl;
                    continue;
                }
                contbusq++;
                contDico++;
                fe1.close();
                continue;

            }

            if(contArch==1){
                if(contbusq==4){
                    contbusq=0;
                    contDico=0;
                    contArch++;
                    continue;
                }
                //cout<<"buscando archivo 2"<<endl;
                string strtemp=guardar;
                ifstream fe2(strtemp.append(to_string(contArch).append(".txt")));
                strtemp="";
                if(fe2.good()) {
                    fe2>>parteS2;
                    fe2.close();
                    contDico=0;
                    contArch++;
                    contbusq=0;
                    //cout<<"se encontro archivo"<<endl;
                    continue;
                }
                contbusq++;
                contDico++;
                fe2.close();
                continue;

            }
            if(contArch==2){
                if(contbusq==4){
                    contbusq=0;
                    contDico=0;
                    contArch++;
                    continue;
                }
                //cout<<"buscando archivo 3"<<endl;
                string strtemp=guardar;
                ifstream fe3(strtemp.append(to_string(contArch).append(".txt")));
                strtemp="";
                if(fe3.good()) {
                    fe3>>parteS3;
                    fe3.close();
                    contDico=0;
                    contArch++;
                    contbusq=0;
                    //cout<<"se encontro archivo"<<endl;
                    continue;
                }
                contbusq++;
                contDico++;
                fe3.close();
                continue;

            }
            if(contArch==3){
                if(contbusq==4){
                    contbusq=0;
                    contDico=0;
                    contArch++;
                    continue;
                }
                //cout<<"buscando archivo 4"<<endl;
                string strtemp=guardar;
                ifstream fe4(strtemp.append(to_string(contArch).append(".txt")));
                strtemp="";
                if(fe4.good()) {
                    fe4>>parteS4;
                    fe4.close();
                    vector<string> p1st=paridad.split(parteS4,"~");
                    p1st.pop_back();
                    p1st.pop_back();
                    parteS4=paridad.vecToString(p1st);
                    contDico=0;
                    contArch++;
                    contbusq=0;
                    //cout<<"se encontro archivo"<<endl;
                    continue;
                }
                contbusq++;
                contDico++;
                fe4.close();
                continue;

            }

        }
        if(parteS1.compare("")==0){
            cout<<"no se encuentra el 1"<<endl;
            parteS1=raid.RAIDString(parteS4,parteS3,parteS2);
        }
        if(parteS2.compare("")==0){
            cout<<"no se encuentra el 2"<<endl;
            parteS2=raid.RAIDString(parteS4,parteS3,parteS1);
        }
        if(parteS3.compare("")==0){
            cout<<"no se encuentra el 3"<<endl;
            parteS3=raid.RAIDString(parteS4,parteS2,parteS1);
        }
        string imag="P3~in#~";
        tx.append("~");
        ty.append("~255~");
        parteS1.append("~");
        parteS2.append("~");
        imag.append(tx.append(ty.append(parteS1.append(parteS2.append(parteS3)))));
        return imag;

    }



};


#endif //MYINVENCIBLELIBRARY_DISCO_H
