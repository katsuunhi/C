#include "stdio.h"

void MaxCol(int a[][3],int m[])
{
	int i,j;
	for(j=0;j<3;j++)
	{
		m[j]=a[0][j];
		for(i=0;i<3;i++)
		{
			if(a[i][j]>m[j])
				m[j]=a[i][j];
		}
	}
}

void main ()
{
	int a[3][3],m[3],i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
		MaxCol(a,m);
		for(i=0;i<3;i++)
			printf("第%d列的最大值为%d\n",i+1,m[i]);
}