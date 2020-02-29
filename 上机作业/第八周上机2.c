#include "stdio.h"
#include "string.h"

void f(char a[][10],int n)
{
	int i,k;
	char temp[10];
	for(i=0;i<n-1;i++)
		for(k=0;k<n-1-i;i++)
		{
			if(strcmp(a[i],a[i+1])>0)
			{
				strcpy(temp,a[i]);
				strcpy(a[i],a[i+1]);
				strcpy(a[i+1],temp);
			}
		}
}
void main ()
{
	char a[10][10];
	int i;
	for(i=0;i<10;i++)
		gets(a[i]);
	f(a,10);
	for(i=0;i<10;i++)
		printf("%s\n",a[i]);
}