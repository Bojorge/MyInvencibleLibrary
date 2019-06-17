//
// Created by manuel on 24/05/19.
//
#include <iostream>
#include "Lista.h"
#include "Paridad.h"



#ifndef MYINVENCIBLELIBRARY_RAID_5_H
#define MYINVENCIBLELIBRARY_RAID_5_H

using namespace std;
Paridad paridad;
class RAID_5 {
public:
    //Funcion Raid que hace XOR con los dos primeros elementos y luego al resultado le aplica XOR con el tercer elemento
    vector<string> RAID5(vector<string> parte1,vector<string> parte2,vector<string> parte3){
        vector<string> partemp=XOR(parte1,parte2);
        vector<string> paridad=XOR(partemp,parte3);
    return paridad;
    }
    //Funcion Raid,genera lo mismo que la anterior pero le entran strings
    string RAIDString(string parte1,string parte2,string parte3){
        vector<string> vec1=paridad.split(parte1,"~");
        vector<string> vec2=paridad.split(parte2,"~");
        vector<string> vec3=paridad.split(parte3,"~");
        return (vecToString(RAID5(vec1,vec2,vec3)));


    }
    //funcion XOR que analiza los terminos en un vector
    vector<string> XOR(vector<string> parte1, vector<string> parte2){
        vector<string> final;
        for(int i=0;i<=parte1.size()-1;i++){ //for que aplica XOR a cada elemento del vector por separado
            string strn1=parte1[i];
            string strn2=parte2[i];
            int n1 = atoi (parte1[i].c_str());
            int n2 = atoi (parte2[i].c_str());

            int xr=n1^n2;
            final.push_back(to_string(xr)); //se agrega el resultado del XOR
        }
        return final;
    }
    //funcion que convierte un vector a un string para menejar la comunicacion
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


#endif //MYINVENCIBLELIBRARY_RAID_5_H
