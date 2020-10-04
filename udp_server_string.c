#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<string.h>
int main()
{ int ss,sb;
  ss=socket(AF_INET,SOCK_DGRAM,0);
  struct sockaddr_in servaddr;
  servaddr.sin_family=AF_INET;
  servaddr.sin_port=ntohs(6011);
  
  servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
  
  bind(ss,(struct sockaddr*)&servaddr,sizeof(struct sockaddr));
  struct sockaddr_in tempsendaddr;
  char buf[1024];
  int len=sizeof(struct sockaddr);
  recvfrom(ss,buf,1024,0,(struct sockaddr*)&tempsendaddr,&len);
  printf("Recived from client : %s",buf);
  for(int i=0;i<strlen(buf);++i)
  { buf[i]=toupper(buf[i]);
  }
  printf("uppercase message is to be send: %s\n",buf);
  struct sockaddr_in client;
  client.sin_family=AF_INET;
  client.sin_port=ntohs(6009);
  
  client.sin_addr.s_addr=inet_addr("127.0.0.1");
  
  sendto(ss,buf,sizeof(buf),0,(struct sockaddr*)&client,sizeof(struct sockaddr));
  
  return 0;
}
