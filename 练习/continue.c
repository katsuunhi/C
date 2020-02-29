#include <stdio.h>

int main ()
{
	int i,j,a=1;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			if(j==1)
				continue;
			a+=a;
		}
	}
	printf("%d",a);


	return 0;
}