#include <iostream>
#include "Cliente.h"

#include <iostream>

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <zconf.h>
#include <arpa/inet.h>
#include <cstdio>
#include <sys/param.h>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <strings.h>
#include <zconf.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

#include <cstdio>
#include <sys/param.h>



using namespace std;

int main() {

    cout<<"\n EL CLIENTE DEBE ENVIAR EL CODIGO 001 \n";
    Cliente cliente;

    cliente.iniciar();
    cout<<"\n *** pasa a la siguiente linea *** \n";
    
    return 0;
}