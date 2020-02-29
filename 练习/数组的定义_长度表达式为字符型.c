#include "stdio.h"

int main ()
{
	static int a['z'],i;
	for(i=0;i<'z';i++)
	{
		printf("%d",a[i]);
	}
	printf("\n%d",i);
	
}