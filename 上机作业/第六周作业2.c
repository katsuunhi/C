#include <stdio.h>

int main ()
{
	int a,n,i,S,temp;
input:
	printf("����������a��n��ֵ��");
	scanf("%d%d",&a,&n);
	if(a<=0||a>=10)
	{
		printf("Date error!Please input again\n");
		goto input;
	}
	S=a;
	temp=a;                                        //temp��ʾ��n�����ֵ���ȸ�ֵa
	for(;n>1;n--,temp=a)                     //n������������ʾ��n��ӵ�n�ʼд����2�ÿ��ѭ��������temp����Ϊa
	{
		for(i=n;i>1;i--)                     //i����ÿһ���a�ĸ���
		{
			temp=temp*10+a;                  //333=(3*10+3)*10+3
		}
		S+=temp;
	}
	printf("���Ϊ%d\n",S);
	return 0;
	
}