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


class Paridad {
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
        return div3;
    }

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
