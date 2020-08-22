#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 4455

int main()
{ int ClientSocket;
  struct sockaddr_in serveraddr;
  char buffer[1024];
  ClientSocket=socket(PF_INET,SOCK_STREAM,0);
  memset(&serveraddr,'\0',sizeof(serveraddr));
  serveraddr.sin_family=AF_INET;
  serveraddr.sin_port=htons(PORT);
  serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
  
  connect(ClientSocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
  recv(ClientSocket,buffer,1024,0);
  printf("Data Recieved: %s",buffer);
  return 0;
}
