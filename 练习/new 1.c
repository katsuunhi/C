#include <stdio.h>
int main()
{
	int i,s,m;
	s = 0;
	printf("Input the number m:\n");
	scanf("%d",&m);
	if(m < 0 || m >= 100)
		printf("ERROR");
	else
	{
		for(i = 0; i < m; i ++)
		{
			if(i%7 == 0)
				s = i*i+s;
		}
		printf("%d",s);
	}
	return 0;
}

