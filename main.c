#include"factory.h"
void* threadfunc(void* p)
{}
int mian(int argc,char* argv[])//传四个参数
{
	if(argc!=5)
	{
		printf("error args\n");
		return -1;
	}
	fac f;
	memset(&f,0,sizeof(f));//开始工厂数据初始化
	f.tnum=atoi(argv[3]);//线程数目
	f.capibility=atoi(argv[4]);//队列能力，模型能够处理的能力
	factory_init(&f,threadfunc);//工厂数据初始化，子线程函数
	factory_start(&f);//启动线程池
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);//初始化一个套接字
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	set_init(sfd,argv[1],argv[2]);//bind IP地址及端口号
	listen(sfd,f.capibility);//同时最大链接数目
	int new_fd;
	while(1)
	{
		new_fd=accept(sfd,NULL,NULL);
		que_add(&f.que,new_fd);
		pthread_cond_signal(&f.cond);
	}
	return 0;
}
