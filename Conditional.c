#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,c;
	int max;
	int ret;
	while((ret=scanf("%d%d%d",&a,&b,&c))!=EOF)
	{
		max=a>b?(a>c?a:c):(b>c?b:c);
		printf("max=%d\n",max);
		return 0;
	}
}
