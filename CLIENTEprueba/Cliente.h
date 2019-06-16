//
// Created by manuel on 14/06/19.
//

#ifndef CLIENTEPRUEBA_CLIENTE_H
#define CLIENTEPRUEBA_CLIENTE_H

#include <iostream>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <zconf.h>

#include <arpa/inet.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

class Cliente {

private:

    char buff[MAX];

public:

    void leerImagen(int sockfd){

        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("Server envia >>> : %s", buff);
    }

    void enviarImagen(int sockfd){

        bzero(buff, sizeof(buff));
        printf("Enviar al servidor >>> : ");
        int n = 0;
        while ((buff[n++] = getchar()) != '\n');
        write(sockfd, buff, sizeof(buff));
    }

    bool terminarConexion(){
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Cliente finalizado...\n");
            return true;
        }
        return false;
    }

    void puerto(int sockfd) {

        for (;;) {

            enviarImagen(sockfd);
            if(terminarConexion()){
                break;
            }

            leerImagen(sockfd);
        }
    };


    int iniciar(){

        int sockfd, connfd;
        struct sockaddr_in servaddr, cli;

        // socket create and varification
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("creacion del socket fallida ...\n");
            exit(0);
        }
        else
            printf("Socket exitosamente creado ...\n");
        bzero(&servaddr, sizeof(servaddr));

        // assign IP, PORT
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);

        // connect the client socket to server socket
        if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
            printf("conexion con el server fallida...\n");
            exit(0);
        }
        else
            printf("se ha conectado al server..\n");

        // function for chat
        puerto(sockfd);

        // close the socket
        close(sockfd);
    };
};


#endif //CLIENTEPRUEBA_CLIENTE_H
