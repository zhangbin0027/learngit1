#include "normal.h"
void send_n(int fd,char *buf,int len)
{
	int total=0;
	int pos;
	while(total<len)
	{
		pos=send(fd,buf+total,len-total,0);
		total=total+pos;
	}
}
void recv_n(int fd,char *buf,int len)
{
	int total=0;
	int pos;
	while(total<len)
	{
		pos=recv(fd,buf+total,len-total,0);
		total=total+pos;
	}
}
