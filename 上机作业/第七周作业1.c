#include "stdio.h"

int main ()
{
	int a[10],i,min,num=1;
	printf("������ʮ������:");
	for(i=0;i<=9;i++)
		scanf("%d",&a[i]);
	min=a[0];
	for(i=1;i<=9;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			num=1;
		}
		else if(a[i]==min)
			num++;
	}

		printf("��С��Ϊ%d,����%d��\n",min,num);
	return 0;
}