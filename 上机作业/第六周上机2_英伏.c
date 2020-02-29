#include "stdio.h"
#include "math.h"
main()
{
	int i,a,n,s,k;
	scanf("%d%d",&a,&n);
	s=0;
	for(i=1;i<=n;i++)
		for(k=0;k<i;k++)
			s+=a*pow(10,k);
		printf("%d",s);
}