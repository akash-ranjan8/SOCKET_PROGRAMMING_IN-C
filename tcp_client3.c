#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void main(){

        int clientSocket;
        struct sockaddr_in serverAddr;
        char buffer[1024];

        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(4444);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

        connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
char  buff[225]="hwh";
        send(clientSocket,buff,strlen(buff),0);
        printf("Connected to Server.\n");

        recv(clientSocket, buffer, 1024, 0);
        printf("Data Recv: %s\n", buffer);

}
