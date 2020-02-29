#include <stdio.h>

int main()
{
	int m,n,i,s=1,a=1;  
input:
	scanf("%d",&n); 
	if(n<=0)                                             //项数为非负数
	{
		printf("Date error!Please input again");
		goto input;
	}
	for(m=2;m<=n;m++)                              //m控制项数，共有n项
	{
		for(i=m*(m+1)/2;i>m*(m-1)/2;i--)          //i控制每一项中数字的个数，每一项的最后一个数为m*（m+1）/2
		{
			a*=i;
		}
		s+=a; 
		a=1;                                     //将1赋值给a，防止上次循环结束时a的值被保留
	}
	printf ("%d\n",s); 
	return 0;
}