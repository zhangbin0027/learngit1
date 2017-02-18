#ifndef __WORK_QUE_H__
#define __WORK_QUE_H__
#include "normal.h"
//队列结点
typedef struct list//定义链表的结点
{
	int new_fd;
	struct list *pnext;
}Node,*pNode;
//队列结构体
typedef struct work_que//定义一个工作链表
{
	pNode phead,ptail;
	pthread_mutex_t mutex;//队列每次操作需要加解锁
	int size;//标识队列实时的长度，便于打印
}que_t,*pque;
void que_init(pque);
void que_add(pque,int);
void que_get(pque,pNode* p_new_fd);
#endif
