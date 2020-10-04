//client code q2
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
       struct mystruct{
          int roll;
         int mark1;
         int mark2;
       };
       struct mystruct ms;
      ms.roll=1829001;
     ms.mark1=87;
     ms.mark2=96;
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(4444);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

        connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
char  buff[225]="Hello KIIT";
        send(clientSocket,&ms,sizeof(ms),0);
        printf("Connected to Server.\n");
       struct mystruct mss;
        recv(clientSocket,&mss , 1024, 0);
        printf("Data Recv: %d\n", mss.roll);
        printf("\n%d\n",mss.mark1);
        printf("\n%d",mss.mark2);

}
