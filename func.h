#ifndef __FACTORY_H__
#define __FACTORY_H__
#include"work_que.h"
#include"normal.h"

#define FILENAME "file"
typedef struct tdata
{
	int len;//代表后面真实数据长度
	char buf[1000];//小火车的长度
}td,*ptd;
void set_init(int,char*,char*);
void send_file(int);
#endif
