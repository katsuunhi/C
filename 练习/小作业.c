#include "stdio.h"
#include "malloc.h"
int af(int *p)
{
	int a=0;
	while (*p!='\0')
	{
		if(*p>'a'&&*p<'z')
			a++;
		p++;
	}
	return a;
}
int bf(int *p)
{
	int a=0;
	while (*p!='\0')
	{
		if(*p>'A'&&*p<'Z')
			a++;
		p++;
	}
	return a;
}
int cf(int *p)
{
	int a=0;
	while (*p!='\0')
	{
		if(*p>'0'&&*p<'9')
			a++;
		p++;
	}
	return a;
}

void main ()
{
	char *p1,*p2;
	int a,b,c;
	p1=(char*)malloc(20*sizeof(char));
	gets(p1);
	a=af(p1);
	b=bf(p1);
	printf("%d\n%d\n%d\n",a,b,c);
	free(p1);

}