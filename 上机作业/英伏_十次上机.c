#include "stdio.h"
#include "malloc.h"

int *MaxRow(int (*p)[3])
{
	int i,j;
	int *max=(int *)malloc(5);
	for(i=0;i<3;i++)
	{
		*(max+i)=**(p+i);
		for(j=0;j<3;j++)
			if(*(*(p+i)+j)>*(max+i))
				*(max+i)=*(*(p+i)+j);
	}
	max[3]=**p;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(i==j&&*(*(p+i)+j)>*(max+3))
				*(max+3)=*(*(p+i)+j);
	return max;
}
void main()
{
	int a[3][3];
	int i,j,(*p)[3],*p1;
	int *max;
    max=(int*)malloc(5*sizeof(int));
	p=a;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",*(p+i)+j);
	max=MaxRow(p);
	for(i=0;i<4;i++)
		printf("%d\n",*(max+i));

}