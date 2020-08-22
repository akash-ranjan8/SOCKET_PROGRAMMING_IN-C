#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main()
{ int fd,res;
  fd=socket(AF_INET,SOCK_DGRAM,0);
  if(fd==-1)
  { printf("SOCKET NOT CREATED\n");
  }
  else
  { printf("SOCKET CREATED\n");
  }
  struct sockaddr_in X;
  X.sin_family=AF_INET;
  X.sin_port=ntohs(6000);
  X.sin_addr.s_addr=INADDR_ANY;
  res=bind(fd,(struct sockaddr *)&X,sizeof(X));
  if(res==-1)
  { printf("BIND IS INSUCCESSFUL\n");
  }
  else
  { printf("BIND IS SUCCESSFUL\n");
  }
  return 0;
}
