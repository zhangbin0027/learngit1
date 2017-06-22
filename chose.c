#include <stdio.h>
#include <stdlib.h>

int main()
{
	int year;
	while(fflush(stdin),scanf("%d",&year)!=EOF)
	{
		if(year%4==0&&year%100!=0||year%400==0)
		{
			printf("year=%d is leap year\n",year);
		}else{
			printf("year=%d is not leap year\n",year);
		}
	}
	return 0;
}
