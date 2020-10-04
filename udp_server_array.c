#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{ int ss,sb;
  ss=socket(AF_INET,SOCK_DGRAM,0);
  struct sockaddr_in servaddr;
  servaddr.sin_family=AF_INET;
  servaddr.sin_port=ntohs(6011);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(ss,(struct sockaddr *)&servaddr,sizeof(struct sockaddr));
    struct sockaddr_in tempsendaddr;
    int buf[5];
    int len=sizeof(struct sockaddr);
    int y= recvfrom(ss,buf,100,0,(struct sockaddr *)&tempsendaddr,&len);
    int i;
    printf("Receive from: ");
     for(i=0;i<5;i++){
    printf(" %d",buf[i]);
  }
    // int i;
   // printf("Receive from : %s",buf);
 close (ss);
 if(y!=-1){
       int cs,bs;
    cs=socket(AF_INET,SOCK_DGRAM,0);

    struct sockaddr_in x;
    x.sin_family=AF_INET;
    x.sin_port=ntohs(6010);
    x.sin_addr.s_addr=inet_addr("127.0.0.1");

    bs=bind(cs,(struct sockaddr *)&x,sizeof(x));
    char msg[100]="thank you",msg1[100];
    int k,j;


    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=ntohs(6012);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
   // strrev(buf);
    sendto(cs,msg,sizeof(msg),0,(struct sockaddr *) &server,sizeof(struct sockaddr));
   close (cs);
}
    }
