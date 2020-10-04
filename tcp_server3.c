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
int n=strlen(buffer);
 int i,c=0;
    for(i=0;i<n/2;i++)
    {
        if(buffer[i]==buffer[n-i-1])
        c++;

        }
        if(c==i){
            printf("string is palindrome");
            strcpy(buffer, "It is palindrome");
       }
    else{
   strcpy(buffer,"It is not palindrome");
}

        send(newSocket, buffer, strlen(buffer), 0);



}
