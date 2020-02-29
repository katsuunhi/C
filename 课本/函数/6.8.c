#include "stdio.h"
#define A 6
void swap(int a[][A],int b[][A],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			b[n][m]=a[m][n];
}