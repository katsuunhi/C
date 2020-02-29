#include <stdio.h>

int main()
{
	int a[2];
	int n, i = 0, sum = 0;
	for(n = 0; n < 2; n ++)
	{
		scanf("%d", &a[n]);
		getchar();
	}
	for(i = 0; i < n; i ++)
	{	
		sum = 0;
		for(b = 1; b < a[i]; b ++)
			sum += b;

		printf("%d\n",b);
	}
}