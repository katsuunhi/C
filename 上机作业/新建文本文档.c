#include <stdio.h>

int main ()
{
	int a,n,i,S,temp;
	scanf("%d%d",&a,&n);
	S=a;
	temp=a;                                        //temp表示第n项的数值，先赋值a
	for(;n>1;n--)                     //n控制项数，表示第n项，从第n项开始写到第2项；每次循环结束将temp重置为a
	{
		for(i=n;i>1;i--)                     //i控制每一项的a的个数
		{
			temp=temp*10+a;                  //333=(3*10+3)*10+3
		}
		S+=temp;
	}
	printf("结果为%d\n",S);
	return 0;
	
}