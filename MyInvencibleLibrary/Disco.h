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
#include <vector>

using namespace std;

class Disco {
public:
    string Disco1="/home/manuel/CLionProjects/MyInvencibleLibrary/DISCO1/";
    string Disco2="/home/manuel/CLionProjects/MyInvencibleLibrary/DISCO2/";
    string Disco3="/home/manuel/CLionProjects/MyInvencibleLibrary/DISCO3/";
    string Disco4="/home/manuel/CLionProjects/MyInvencibleLibrary/DISCO4/";
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
        v4=raid.RAID5(v1,v2,v3);

        srand(time(NULL));

        int Discorand=0 + rand() % (3 +1 - 0) ;
        int vect=0;
        while(vect<4){
            //cout<<"metiendo el vector "<<vect<<endl;
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
                ofstream archivo(ruta.append(".txt"));
                archivo<<raid.vecToString(guardar);
                cout<<"abierto" <<archivo.is_open()<<endl;
                archivo.close();
                cout<<"abierto" <<archivo.is_open()<<endl;
                vect++;
                Discorand++;
                continue;
            }
            if(Discorand==1){
                string codigo=cod;
                codigo=codigo.append(to_string(vect));
                string ruta=Disco2.append(codigo);
                ofstream archivo(ruta.append(".txt"));
                archivo<<raid.vecToString(guardar);
                archivo.close();
                vect++;
                Discorand++;
                continue;
            }
            if(Discorand==2){
                string codigo=cod;
                codigo=codigo.append(to_string(vect));
                string ruta=Disco3.append(codigo);
                ofstream archivo(ruta.append(".txt"));
                archivo<<raid.vecToString(guardar);
                archivo.close();
                vect++;
                Discorand++;
                continue;
            }
            if(Discorand==3){
                string codigo=cod;
                codigo=codigo.append(to_string(vect));
                string ruta=Disco4.append(codigo);
                ofstream archivo(ruta.append(".txt"));
                archivo<<raid.vecToString(guardar);
                archivo.close();
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
                cout<<"buscando archivo 1"<<endl;
                string strtemp=guardar;
                ifstream fe(strtemp.append(to_string(contArch).append(".txt")));
                strtemp="";
                if(fe.good()) {
                    fe>>parteS1;
                    cout<<parteS1<<endl;
                    fe.close();
                    contDico=0;
                    contArch++;
                    contbusq=0;
                    cout<<"se encontro archivo"<<endl;
                    continue;
                }else{contbusq++;contDico++;continue;}
            }

            if(contArch==1){
                if(contbusq==4){
                    contbusq=0;
                    contDico=0;
                    contArch++;
                    continue;
                }
                cout<<"buscando archivo 2"<<endl;
                string strtemp=guardar;
                ifstream fe(strtemp.append(to_string(contArch).append(".txt")));
                strtemp="";
                if(fe.good()) {
                    fe>>parteS2;
                    cout<<parteS2<<endl;
                    fe.close();
                    contDico=0;
                    contArch++;
                    contbusq=0;
                    cout<<"se encontro archivo"<<endl;
                    continue;
                }else{contbusq++;contDico++;continue;}
            }
            if(contArch==2){
                if(contbusq==4){
                    contbusq=0;
                    contDico=0;
                    contArch++;
                    continue;
                }
                cout<<"buscando archivo 3"<<endl;
                string strtemp=guardar;
                ifstream fe(strtemp.append(to_string(contArch).append(".txt")));
                strtemp="";
                if(fe.good()) {
                    fe>>parteS3;
                    cout<<parteS3<<endl;
                    fe.close();
                    contDico=0;
                    contArch++;
                    contbusq=0;
                    cout<<"se encontro archivo"<<endl;
                    continue;
                }else{contbusq++;contDico++;continue;}
            }
            if(contArch==3){
                if(contbusq==4){
                    contbusq=0;
                    contDico=0;
                    contArch++;
                    continue;
                }
                cout<<"buscando archivo 4"<<endl;
                string strtemp=guardar;
                ifstream fe(strtemp.append(to_string(contArch).append(".txt")));
                strtemp="";
                if(fe.good()) {
                    fe>>parteS4;
                    cout<<parteS4<<endl;
                    fe.close();
                    contDico=0;
                    contArch++;
                    contbusq=0;
                    cout<<"se encontro archivo"<<endl;
                    continue;
                }else{contbusq++;contDico++;continue;}
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
        parteS1.append("~");
        parteS2.append("~");
        parteS1.append(parteS2.append(parteS3));
        return parteS1;

    }



};


#endif //MYINVENCIBLELIBRARY_DISCO_H
