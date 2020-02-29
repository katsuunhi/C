#include "stdio.h"
void stod(int n)
{
	int i;
	if(n<0)
	{
		putchar('-');
		n=-n;
	}
	if((i=n/10)!=0)
		stod(i);
	purchar(n%10+'0');
}
int main ()
{
	int n=233;
	stod(n);
}