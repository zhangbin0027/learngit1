#include "factory.h"
void factory_init(pfac p,pthfunc entry)
{
	p->pth=(pthread_t*)calloc(p->tnum,sizeof(pthread_t));
	p->entry=entry;//线程入口函数初始化
	pthread_cond_init(&p->cond,NULL);//对条件变量进行初始化
	que_init(&p->que);//队列初始化的函数，需要再写一个work_que.c
	p->start=0;
}
void factory_start(pfac p)
{
	int i;
	if(0==p->start)
	{
		for(i=0;i<tnum;i++)
		{
			pthread_create(&p->pth[i],NULL,p->entry,p);
		}//将每一个工厂的数据结构都给每一个线程
		p->start=1;
	}else{
		printf("factory has started\n");//工厂已启动
	}
}
