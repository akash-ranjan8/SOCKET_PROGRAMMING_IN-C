//server q2 code
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
       struct mystruct{
        int roll;
        int marks;
        int marks2;
};
       struct mystruct mss;
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(4444);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

        bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        listen(sockfd, 5);


        newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);

        recv(newSocket,&mss,1024,0);
        printf("\n%d\n",mss.roll);
        printf("\n%d",mss.marks);
        printf("]n%d",mss.marks2);
        int x= mss.marks;
        mss.marks=mss.marks2;
       mss.marks2=x;
        strcpy(buffer, "Thank you!!");
        send(newSocket, &mss, sizeof(mss), 0);



}
