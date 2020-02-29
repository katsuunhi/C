#include <stdio.h>

int main ()
{
	int *p,a[10],i,min;
	p=a;
	printf("please input 10 nums:");
	for(i=0;i<=9;i++)
	{
		scanf("%d",p+i);
	}
	min=*p;
	for(i=0;i<=9;i++)
	{
		if(min>*p)
		{
			min=*p;
			p++;
		}
	}
	printf("the minxnum is %d\n",min);

	return 0;
}