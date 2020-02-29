#include <stdio.h>

void change(int n,int *p)
{
	n=50;
	*p=50;
}

int main ()
{
	int n=100,m=100;
	int *p=&m;
	printf("%d %d\n",n,*p);
	change(n,p);
	printf("%d %d",n,*p);
}