//
// Created by manuel on 14/06/19.
//

#ifndef MYINVENCIBLELIBRARY_BINDEC_H
#define MYINVENCIBLELIBRARY_BINDEC_H

#include <iostream>
#include <cmath>
//using namespace std;

class BinDec {

public:
    int binAdeci(double binario)
    {
        int exp,digito;
        //double binario, decimal;
        double decimal;
        //std::cout << "Introduce numero: ";
        //std::cin >> binario;
        exp=0;
        decimal=0;
        while(((int)(binario/10))!=0)
        {
            digito = (int)binario % 10;
            decimal = decimal + digito * pow(2.0,exp);
            exp++;
            binario=(int)(binario/10);
        }
        decimal=decimal + binario * pow(2.0,exp);
        cout << endl << "Decimal: " << decimal << endl;
        return decimal;
    }


    int decAbina(int D)
    {
        int D1,D2,D3,D4,D5,D6,D7,D8,R1str,R2str,R3str,R4str,R5str, R6str,R7str,R8str,R1, R2, R3, R4, R5, R6, R7, R8;
        string binarioStr;
        int binario;
        if ((D>255)||(D<0))
            cout<<"solo numeros del 0 al 225"<<endl;
        else
        {
            D1=D/2;R1str=D%2;
            D2=D1/2;R2str=D1%2;
            D3=D2/2;R3str=D2%2;
            D4=D3/2;R4str=D3%2;
            D5=D4/2;R5str=D4%2;
            D6=D5/2;R6str=D5%2;
            D7=D6/2;R7str=D6%2;
            R8str=D7%2;
            //D8=D7/2;
            binarioStr=std::to_string(R8str)+std::to_string(R7str)+std::to_string(R6str)+std::to_string(R5str)+std::to_string(R4str)+std::to_string(R3str)+std::to_string(R2str)+std::to_string(R1str);
            binario= (R1str * pow(10, 0) + R2str * pow(10, 1) + R3str * pow(10, 2) + R4str * pow(10, 3) + R5str * pow(10, 4) + R6str * pow(10, 5) + R7str * pow(10, 6) + R8str * pow(10, 7));
        }
        cout << endl << "Binario: " << binario << endl;
        return binario;
    }

};


#endif //MYINVENCIBLELIBRARY_BINDEC_H
