//
// Created by manuel on 15/06/19.
//

#ifndef MYINVENCIBLELIBRARY_SERVIDOR_H
#define MYINVENCIBLELIBRARY_SERVIDOR_H

#include <zconf.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <zconf.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "Disco.h"
#include "Paridad.h"

#define MAX 800
#define PORT 8080
#define SA struct sockaddr



class Servidor {
Paridad paridad;
private:
    Disco disco;
    int sockfd, connfd;
    unsigned int len;
    struct sockaddr_in servaddr, cli;
    char buff[MAX];
    string readed;


public:

    bool leerImagen(int sockfd){
        printf("\n ... leyendo ...  \n");
        bzero(buff, MAX);
        printf("\n ... leyendo ...  \n");
        // read the message from client and copy it in buffer
        read(sockfd, buff, sizeof(buff));

        printf("\n ... leyendo ...  \n");
        //char buffer[500];
        //string o(buff);
        string o=buff;
        //strcpy(buffer, o.c_str());
        cout<<"tamano del buff "<< sizeof(buff)<<endl;
        cout<<"tamano del string "<<o.size()<<endl;
        cout<<"valor de O "<<o<<endl;
        string cod;

        cout<<"tamano del string "<<cod<<endl;

        if(o.size()==4){
            cod+=o[0];
            cod+=o[1];
            cod+=o[2];
        //if (strncmp(buffer, buff, 3) == 0) {
            printf("\n Se recibio el codigo  \n");
            char pixeles [500];
            string x=disco.READ(cod);
            strcpy(pixeles, x.c_str());
            write(sockfd, pixeles, sizeof(buff));
            bzero(buff, MAX);
            return true;

        }

        if(o.size()>4) {
            cout<<"valor de O "<<o<<endl;
            disco.WRITE(o);
            write(sockfd, " ok ", sizeof(buff));
            bzero(buff, MAX);
            //printf("cliente envia >>> : %s\t");
            return true;
        }

    }
    void enviarImagen(int sockfd){
        bzero(buff, MAX);
        printf("Enviar al cliente >>> : ", buff);
        bzero(buff, MAX);
        int n=0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n');
        write(sockfd, buff, sizeof(buff));
    }

    void enviarImagen(int sockfd,string texto){
        bzero(buff, MAX);
       int tamano=texto.length();
       char txt[tamano];
       for(int i=0;i<tamano;i++){
           txt[i]=texto[i];
       }
        for(int i=0;i<tamano;i++){
            buff[i]=txt[i];
        }
        //strcpy(x,texto.c_str());
        printf("Enviar al cliente >>> : ", buff);
        bzero(buff, MAX);

        int n=0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n');
        write(sockfd, buff, sizeof(buff));

    }

    bool terminarConexion(){
        return true;
    }


    void puerto(int sockfd){
        // infinite loop for chat
        for (;;) {

            if(leerImagen(sockfd)){
                break;
            };


            //enviarImagen(sockfd);


            if(terminarConexion()){
                break;
            }
        }

    };

    int reiniciar(){

        // socket create and verification
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("\n reinicio de conexion:  *** fallido ***\n");
            exit(0);
        } else
            printf("\n reinicio exitoso \n");
        bzero(&servaddr, sizeof(servaddr));

        // assign IP, PORT
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(PORT);

        // Binding newly created socket to given IP and verification
        if ((bind(sockfd, (SA *) &servaddr, sizeof(servaddr))) != 0) {
            printf("Fallo el enlace al socket ...\n");
            exit(0);
        } else
            printf("Socket exitosamente enlazado..\n");

        // Now server is ready to listen and verification
        if ((listen(sockfd, 5)) != 0) {
            printf("Listen failed...\n");
            exit(0);
        } else
            printf("\n Servidor escuchando ...\n");
        len = sizeof(cli);

        // Accept the data packet from client and verification
        connfd = accept(sockfd, (SA *) &cli, &len);
        if (connfd < 0) {
            printf("server acccept failed...\n");
            exit(0);
        } else
            printf("server acccept the client...\n");

        // Function for chatting between client and server
        puerto(connfd);


        // After chatting close the socket
        close(sockfd);
        sleep(2);
        iniciar();
    }

    int iniciar() {

        // socket create and verification
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("creacion del socket fallida ...\n");
            close(sockfd);
            sleep(2);
            reiniciar();
            exit(0);
        } else
            printf("Socket exitosamente creado ...\n");
        bzero(&servaddr, sizeof(servaddr));

        // assign IP, PORT
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(PORT);

        // Binding newly created socket to given IP and verification
        if ((bind(sockfd, (SA *) &servaddr, sizeof(servaddr))) != 0) {
            printf("Fallo el enlace al socket ...\n");
            close(sockfd);
            sleep(2);
            reiniciar();
            exit(0);
        } else
            printf("Socket exitosamente enlazado..\n");

        // Now server is ready to listen and verification
        if ((listen(sockfd, 5)) != 0) {
            printf("Listen failed...\n");
            close(sockfd);
            sleep(2);
            reiniciar();
            exit(0);
        } else
            printf("\n Servidor escuchando ...\n");
        len = sizeof(cli);

        // Accept the data packet from client and verification
        connfd = accept(sockfd, (SA *) &cli, &len);
        if (connfd < 0) {
            printf("server acccept failed...\n");
            close(sockfd);
            sleep(2);
            reiniciar();
            exit(0);
        } else
            printf("\n El servidor acepta al cliente ...\n");

        // Function for chatting between client and server
        puerto(connfd);


        // After chatting close the socket
        close(sockfd);
        sleep(2);
        reiniciar();
    };


};



#endif //MYINVENCIBLELIBRARY_SERVIDOR_H
