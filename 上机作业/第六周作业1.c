#include <stdio.h>

int main()
{
	int m,n,i,s=1,a=1;  
input:
	scanf("%d",&n); 
	if(n<=0)                                             //����Ϊ�Ǹ���
	{
		printf("Date error!Please input again");
		goto input;
	}
	for(m=2;m<=n;m++)                              //m��������������n��
	{
		for(i=m*(m+1)/2;i>m*(m-1)/2;i--)          //i����ÿһ�������ֵĸ�����ÿһ������һ����Ϊm*��m+1��/2
		{
			a*=i;
		}
		s+=a; 
		a=1;                                     //��1��ֵ��a����ֹ�ϴ�ѭ������ʱa��ֵ������
	}
	printf ("%d\n",s); 
	return 0;
}