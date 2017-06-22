#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int i;
	float j;
	while(fflush(stdin),scanf("%d%f",&i,&j)!=EOF)
	{
		printf("i=%d,j=%5.2f\n",i,j);
	}
	return 0;
}
