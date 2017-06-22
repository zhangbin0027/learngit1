#ifndef __FACTORY_H__
#define __FACTORY_H__
#include "work_que.h"
#include "normal.h"

typedef void* (*pthfunc)(void*);//线程入口函数
typedef struct factory
{
	pthread_t *pth;//指针指向一个结构体数组
	int tnum;//创建的线程数目
	pthfunc entry;
	pthread_cond_t cond;
	int capibility;//线程最大的能力
	que_t que;//定义队列
	int start;//避免线程重复启动
}fac*pfac;
void set_init(int,char*,char*);
void send_file(int);
void factory_init(pfac,pthfunc);
void factory_start(pfac);
#endif
