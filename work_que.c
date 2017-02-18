#include"work_que.h"
void que_init(pque p)
{
	memset(p,0,sizeof(que_t));//对que进行初始化
	pthread_mutex_init(&p->mutex,NULL);
}
