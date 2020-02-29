#include "stdio.h"
#include "math.h"

int main()
{
	int h,g,t;
	printf("enter:\n");
	scanf("%d",&t);
	g=10;
	if(t<=5)
	{
		h=1.0/2*g*pow(t,2);
		printf("t=%d,h=%d,g=%d\n",t,h,g);
	}
	else
		printf("wrong\n");

	return 0;

}