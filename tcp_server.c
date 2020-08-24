#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 4455

int main()
{ int sockfd;
  struct sockaddr_in serveraddr;
  
  int newsocket;
  struct sockaddr_in newaddr;
  
  socklen_t addr_size;
  char buffer[1024];
  
  sockfd=socket(PF_INET,SOCK_STREAM,0);
  memset(&serveraddr,'\0',sizeof(serveraddr));
  
  serveraddr.sin_family=AF_INET;
  serveraddr.sin_port=htons(PORT);
  serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
  
  bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
  
  listen(sockfd,5);
  addr_size=sizeof(newaddr);
  
  newsocket=accept(sockfd,(struct sockaddr*)&newaddr,&addr_size);
  
  strcpy(buffer,"akash");
  send(newsocket,buffer,strlen(buffer),0);
  return 0;
}
