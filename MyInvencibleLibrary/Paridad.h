//
// Created by manuel on 24/05/19.
//

#ifndef MYINVENCIBLELIBRARY_PARIDAD_H
#define MYINVENCIBLELIBRARY_PARIDAD_H

#include "Lista.h"
#include <iostream>
#include <fstream>
//#include "RAID_5.h"
using namespace std;


class Paridad {
public:
    //funcion que convierte una imagen a un string para manejarlo en la comunicacion
    string imgTostring(string imagen) { //Imagen tiene el string entero de la direccion de la imagen
        char cadena[128];
        string strdatos;
        ifstream fe(imagen);  // se abre la imagen con la direccion asignada
        while (!fe.eof()) {
            fe >> cadena; //se lee cada linea de el archivo
            string numdato=cadena;
            strdatos.append(numdato); // se agrega la linea al string
            strdatos.append("~");
        }
        fe.close();
        vector<string> nums=split(strdatos,"~");
        nums.pop_back();
        nums.pop_back();
        return vecToString(nums);
    }
    //funcion que divide un string en 3 diferentes pares para almacenarlas en cada disco
    vector<vector<string>> dividir(string texta){
        vector<string> datos;
        vector<vector<string>> div3;
        vector<string> division=split (texta,"in~"); // se eliminan los primeros elementos de la imagen
        string ret=division[1];
        vector<string> separados=split(ret,"~"); // se divide el archivo en partes
        string tX=separados[0];
        string tY=separados[1];
        cout<<tX<<"   "<<tY<<endl;
        for(int i=3;i<=separados.size()-1;i++){
            string dta=separados[i];
            datos.push_back(dta);
        }
        vector<string> v1;
        vector<string> v2;
        vector<string> v3;
        int cantEntre3 =(datos.size())/3;
        int intervalo1=cantEntre3;
        int intervalo2=cantEntre3*2;
        int intervalo3=datos.size()-1;
        for(int a=0;a<=intervalo1-1;a++){//se divide la primera parte del archivo entero
            v1.push_back(datos[a]);
        }
        for(int b=intervalo1;b<=intervalo2-1;b++){ //se divide la segunda parte del archivo entero
            v2.push_back(datos[b]);
        }
        for(int c=intervalo2;c<=intervalo3;c++){//se divide la tercera parte del archivo entero
            v3.push_back(datos[c]);
        }
        v1.push_back(tX);
        v1.push_back(tY);
        div3.push_back(v1);
        div3.push_back(v2);
        div3.push_back(v3);

        return div3;
    }
    //Funcion que le ingresa un string para convertirlo a una imagen
    void strTimg(string imagen,string nombre){
        nombre.append(".ppm");
        string direccion="/home/aaron/Desktop/";
        direccion.append(nombre);
        ofstream fs(direccion);
        vector<string> datos=split(imagen,"~");
        for(int i=0;i<=datos.size()-1;i++){
            fs<<datos[i]<<endl;
        }
        fs.close();
    };

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
    string vecToString(vector<string> lista){
        string vTs;
        for(int i=0;i<=lista.size()-2;i++){
            //cout<<lista[i]<<endl;
            vTs.append(lista[i]);
            vTs.append("~");
        }
        vTs.append(lista[lista.size()-1]);
        return vTs;
    }
};

#endif //MYINVENCIBLELIBRARY_PARIDAD_H
