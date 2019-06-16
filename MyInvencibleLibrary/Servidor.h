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

#define MAX 80
#define PORT 8080
#define SA struct sockaddr



class Servidor {

private:
    int sockfd, connfd;
    unsigned int len;
    struct sockaddr_in servaddr, cli;
    char buff[MAX];


public:

    void leerPaquete(int sockfd){
        bzero(buff, MAX);

        // read the message from client and copy it in buffer
        read(sockfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        printf("cliente envia >>> : %s\t");
        if (strncmp("001", buff, 4) == 0) {
            //BuscarEnDisco("001");
        }
    }

    void enviarPaquete(int sockfd){
        bzero(buff, MAX);
        printf("Enviar al cliente >>> : ", buff);
        bzero(buff, MAX);
        int n=0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n');
        write(sockfd, buff, sizeof(buff));


    }

    bool terminarConexion(){
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Finalizado...\n");
            return true;
        }
        return false;
    }


    void puerto(int sockfd){
        // infinite loop for chat
        for (;;) {

            leerPaquete(sockfd);
            enviarPaquete(sockfd);

            if(terminarConexion()){
                break;
            }
        }
    };


    int iniciar() {

        // socket create and verification
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("creacion del socket fallida ...\n");
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
            exit(0);
        } else
            printf("Socket exitosamente enlazado..\n");

        // Now server is ready to listen and verification
        if ((listen(sockfd, 5)) != 0) {
            printf("Listen failed...\n");
            exit(0);
        } else
            printf("Server listening..\n");
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
    };
};


#endif //MYINVENCIBLELIBRARY_SERVIDOR_H
