//CLIENT SENDS A MESSAGE AND SERVER RECIEVES IT 
//UDP
#include<stdio.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{ int cs,bs;
  cs=socket(AF_INET,SOCK_DGRAM,0);
  
  struct sockaddr_in x;
  x.sin_family=AF_INET;
  x.sin_port=ntohs(6009);
  x.sin_addr.s_addr=inet_addr("127.0.0.1");
  
  bs=bind(cs,(struct sockaddr*)&x,sizeof(x));
  char msg[]="HELLO KIIT",msg1[100];
  
  struct sockaddr_in server;
  server.sin_family=AF_INET;
  server.sin_port=ntohs(6011);
  
  server.sin_addr.s_addr=inet_addr("127.0.0.1");
  
  sendto(cs,msg,sizeof(msg),0,(struct sockaddr*)&server,sizeof(struct sockaddr));
  close(cs);
  return 0;
}
 
