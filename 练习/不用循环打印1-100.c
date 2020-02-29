#include "stdio.h"
void test(int n);
int main ()
{
	int i;
	scanf("%d",&i);
	test(i);
	return 0;
}

void test(int n)
{
	if(n==1)
		return 1;
	else
	{
		printf("%d",n);
		n--;
		test(n);
	}

}