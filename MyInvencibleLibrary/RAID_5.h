//
// Created by manuel on 24/05/19.
//
#include <iostream>
#include <bitset>
#include "Lista.h"
#include "Paridad.h"



#ifndef MYINVENCIBLELIBRARY_RAID_5_H
#define MYINVENCIBLELIBRARY_RAID_5_H

using namespace std;
class RAID_5 {
public:
    vector<string> RAID5(vector<string> parte1,vector<string> parte2,vector<string> parte3){
        vector<string> partemp=XOR(parte1,parte2);
        vector<string> paridad=XOR(partemp,parte3);
    return paridad;
    }
    vector<string> XOR(vector<string> parte1, vector<string> parte2){
        vector<string> final;
        for(int i=0;i<=parte1.size()-1;i++){
            string strn1=parte1[i];
            string strn2=parte2[i];
            int n1 = atoi (parte1[i].c_str());
            int n2 = atoi (parte2[i].c_str());

            int xr=n1^n2;
            final.push_back(to_string(xr));
        }
        return final;
    }
    string vecToString(vector<string> lista){
        string vTs;
        for(int i=0;i<=lista.size()-2;i++){
            cout<<lista[i]<<endl;
            vTs.append(lista[i]);
            vTs.append(",");
        }
        vTs.append(lista[lista.size()-1]);
        return vTs;
    }

};


#endif //MYINVENCIBLELIBRARY_RAID_5_H
