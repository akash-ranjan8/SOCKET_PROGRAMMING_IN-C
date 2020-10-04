//client code q1
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <unistd.h>
#include<stdio.h>
int main()
  {
    int cs,bs;
    cs=socket(AF_INET,SOCK_DGRAM,0);

    struct sockaddr_in x;
    x.sin_family=AF_INET;
    x.sin_port=ntohs(6009);
    x.sin_addr.s_addr=inet_addr("127.0.0.1");

    bs=bind(cs,(struct sockaddr *)&x,sizeof(x));
    char msg[100],msg1[100];
    int arr[5]={2,3,4,5,6};
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=ntohs(6011);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

   int y= sendto(cs,arr,sizeof(arr),0,(struct sockaddr *) &server,sizeof(struct sockaddr));
   close (cs);
 if(y!=-1){
  int ss,sb;
  ss=socket(AF_INET,SOCK_DGRAM,0);
  struct sockaddr_in servaddr;
  servaddr.sin_family=AF_INET;
  servaddr.sin_port=ntohs(6012);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(ss,(struct sockaddr *)&servaddr,sizeof(struct sockaddr));
    struct sockaddr_in tempsendaddr;
    int buf[5];
    int len=sizeof(struct sockaddr);

    int x= recvfrom(ss,buf,100,0,(struct sockaddr *)&tempsendaddr,&len);
    printf("Receive from : %d",buf[0]);
   close (ss);
}
    }
