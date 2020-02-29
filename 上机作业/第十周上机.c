/*#include "stdio.h"
#include "stdlib.h"
#define A 3

int *MaxRow(int (*p)[A])
{
	int i,j;
	int *max=(int *)malloc(A+1);
	*(max+A)=**p;
	for(i=0;i<A;i++)
	{
		*(max+i)=**(p+i);
		for(j=0;j<A;j++)
			if(*(*(p+i)+j)>*(max+i))
				*(max+i)=*(*(p+i)+j);
	}
	for(i=0;i<A;i++)
		for(j=0;j<A;j++)
			if(i==j&&*(*(p+i)+j)>*(max+A))
				*(max+A)=*(*(p+i)+j);
	return max;
}
void main()
{
	int a[A][A];
	int i,j,(*p)[A];
	int *max;
    max=(int*)malloc(A+1);
	p=a;
	for(i=0;i<A;i++)
		for(j=0;j<A;j++)
			scanf("%d",*(p+i)+j);
	max=MaxRow(p);


	for(i=0;i<A+1;i++)
//		for(j=0;j<3;j++)
		printf("%d\n",*(max+i));

}*/
#include "stdio.h"
#include "malloc.h"
int *MaxRow(int (*p)[3])
{
	int i,j;
	int *max=(int *)malloc(5*sizeof(int));
	for(i=0;i<3;i++)
	{
		*(max+i)=**(p+i);
		for(j=0;j<3;j++)
			if(*(*(p+i)+j)>*(max+i))
				*(max+i)=*(*(p+i)+j);
	}
	*(max+3)=**p;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(i==j&&*(*(p+i)+j)>*(max+3))
				*(max+3)=*(*(p+i)+j);
	return max;
}
void main()
{
	int a[3][3];
	int i,j,(*p)[3];
	int *max=(int*)malloc(5*sizeof(int));
	p=a;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",*(p+i)+j);
	max=MaxRow(p);
	for(i=0;i<3;i++)
		printf("第%d行的最大值为%d\n",i,*(max+i));
    printf("主对角线的最大值为%d\n",*(max+3));
}


//计日1502_赵英伏