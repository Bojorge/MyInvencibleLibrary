//
// Created by manuel on 24/05/19.
//

#ifndef MYINVENCIBLELIBRARY_PARIDAD_H
#define MYINVENCIBLELIBRARY_PARIDAD_H

#include "Lista.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Paridad2 {
public:
    string convString(string imagen) {
        char cadena[128];
        string strdatos;
        ifstream fe(imagen);
        while (!fe.eof()) {
            fe >> cadena;
            string numdato=cadena;
            strdatos.append(numdato);
            strdatos.append(",");
        }
        fe.close();
        return strdatos;
    }


    string dividir(string texto, int parte){
        int tamanoTexto;
        string aDividir;
        string division1;
        string division2;
        string division3;
        int contador=0;
        for(int i=0;i<(texto.length());i++){
            if(texto[i]!=' ' && texto[i]!='\n'){
                aDividir+=texto[i];
                //cout<<contador<<" "<<texto[i]<<endl;
            }
            else if(texto[i]==' '){
                aDividir+=",";
                contador+=1;
            }


        }
        for(int i=0;i<aDividir.length();i++){
            if( i==(aDividir.length())-1){
                break;
            }
            else if(aDividir[i]!=',' && i<(aDividir.length()/3)){
                division1+=aDividir[i];
            }
            else if(aDividir[i]==',' && i<(aDividir.length()/3)){
                division1+=",";
            }

            else if(aDividir[i]!=',' && i>=(aDividir.length()/3) && i<(aDividir.length()/3)*2){
                division2+=aDividir[i];

            }
            else if(aDividir[i]==',' && i>=(aDividir.length()/3) && i<(aDividir.length()/3)*2){
                division2+=",";
            }

            else if(aDividir[i]!=',' && i>=((aDividir.length()/3)*2)){
                division3+=aDividir[i];

            }
            else if(aDividir[i]==',' && i>=((aDividir.length()/3)*2)){
                division3+=",";
            }


        }

        int contadorZ=0;
        int contadorY=0;
        int contadorX=0;
        for(int i=0;i<(division2.length());i++) {
            if (division2[i] != ',') {

            } else if (division2[i] == ',') {
                contadorY += 1;
            }
        }
        for(int i=0;i<(division1.length());i++) {
            if (division1[i] != ',') {

            } else if (division1[i] == ',') {
                contadorX += 1;
            }
        }
        for(int i=0;i<(division3.length());i++) {
            if (division3[i] != ',') {

            } else if (division3[i] == ',') {
                contadorZ += 1;
            }
        }


/*
        cout<<"Cantidad de pixeles  "<<contador<<endl;
        cout<<"Division 1  "<<division1<<endl;
        cout<<"Division 2  "<<division2<<endl;
        cout<<"Division 3  "<<division3<<endl;
        cout<<"Cantidad de pixeles en la division 1  "<<contadorX<<endl;
        cout<<"Cantidad de pixeles en la division 2  "<<contadorY<<endl;
        cout<<"Cantidad de pixeles en la division 3  "<<contadorZ<<endl;
        int suma=0;
        suma+= contadorZ+contadorY+contadorX;
        cout<<"SUMA de las 3 divisiones "<<suma<<endl;
*/

        cout<<"resultado "<<parte<<endl;
        if(parte==1){
            cout<<division1<<endl;
            return division1;
        }
        if(parte==2){
            cout<<division2<<endl;
            return division2;
        }
        if(parte==3){
            cout<<division3<<endl;
            return division3;
        }

    }

    /*
    vector<vector<string>> dividir(string texta){
        vector<string> datos;
        vector<vector<string>> div3;
        vector<string> division=split (texta,"in,");
        string ret=division[1];
        vector<string> separados=split(ret,",");

        for(int i=3;i<=separados.size()-1;i++){
            string dta=separados[i];
            datos.push_back(dta);
        }
        vector<string> v1;
        vector<string> v2;
        vector<string> v3;
        int cantEntre3 =(datos.size()-1)/3;
        int intervalo1=cantEntre3;
        int intervalo2=cantEntre3*2;
        int intervalo3=datos.size()-1;
        for(int a=0;a<=intervalo1-1;a++){
            v1.push_back(datos[a]);
        }
        for(int b=intervalo1+1;b<=intervalo2;b++){
            v2.push_back(datos[b]);
        }
        for(int c=intervalo2+1;c<=intervalo3;c++){
            v3.push_back(datos[c]);
        }
        div3.push_back(v1);
        div3.push_back(v2);
        div3.push_back(v3);

        for(int i=0;i<=v1.size();i++){
            cout<<v1[i]<<endl;
        }
        return div3;
    }
*/

    vector<string> split (string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }
};


#endif //MYINVENCIBLELIBRARY_PARIDAD_H
