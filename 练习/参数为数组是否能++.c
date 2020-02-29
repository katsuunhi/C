#include "stdio.h"
void f(char a[])
{
	a++;
	printf("%s",a);
}
void main ()
{
	char a[5]="heo";
	a++;
	f(a);
}