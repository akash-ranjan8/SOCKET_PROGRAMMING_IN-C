#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void main(){

        int sockfd;
        struct sockaddr_in serverAddr;

        int newSocket;
        struct sockaddr_in newAddr;

        socklen_t addr_size;
        char buffer[1024];

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(4444);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

        bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        listen(sockfd, 5);


        newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);

        recv(newSocket,buffer,1024,0);
        printf("\n%s\n",buffer);
        strcpy(buffer, "Thank you!!");
        send(newSocket, buffer, strlen(buffer), 0);



}
