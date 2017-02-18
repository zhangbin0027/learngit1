#include"normal.h"
void send_file(int new_fd)
{
	td t;
	memeset(&t,0,sizeof(t));
	t.len=strlen(FILENAME);
	strcpy(t.buf,FOLENAME);
	send_n(new_fd,&t,4+t.len);
	int fd;
	fd=open(FILENAME,O_RDONLY);
	if(-1==fd)
	{
		perror("open");
		return;
	}
	while(memset(&t,0,sizeof(t)),(t.len=read(fd,t.buf,sizeof(t.buf)))>0)
	{
		send_n(new_fd,&t,4+t.len);
	}
	t.len=0;
	send_n(new_fd,&t.len,4);
	close(new_fd);
}
