#include "stdio.h"

int main ()
{
	int S=0,a,b=1,n,i,k;
	printf("ÇëÊäÈëÏîÊı:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a=1;
		for(k=1;k<=i;k++)
		{
			a*=b;
			b++;
		}
		S+=a;
	}
	printf("%d",S);
	
	return 0;
}