#include<stdio.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
int main()
{ int cs,bs;
  cs=socket(AF_INET,SOCK_DGRAM,0);
  
  struct sockaddr_in x;
  x.sin_family=AF_INET;
  x.sin_port=ntohs(6009);
  x.sin_addr.s_addr=inet_addr("127.0.0.1");
  
  bs=bind(cs,(struct sockaddr*)&x,sizeof(x));
  char buffer[1024];
 
    printf("enter the string\n");
    fgets(buffer,sizeof(buffer),stdin);
    printf("typed message: %s\n",buffer);
    int b=strlen(buffer)+1;
  struct sockaddr_in server;
  server.sin_family=AF_INET;
  server.sin_port=ntohs(6011);
  
  server.sin_addr.s_addr=inet_addr("127.0.0.1");
  
  sendto(cs,buffer,sizeof(buffer),0,(struct sockaddr*)&server,sizeof(struct sockaddr));
  struct sockaddr_in tempsendaddr;
  char buf[1024];
  int len=sizeof(struct sockaddr);
  recvfrom(cs,buf,1024,0,(struct sockaddr*)&tempsendaddr,&len);
  printf("Recive from server is: %s\n",buf);
  close(cs);
  return 0;
}
 
