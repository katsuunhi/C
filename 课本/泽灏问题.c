//�ַ������ݻ�ʶ��ո�ͻس������������ʱ���ð��ո�ͻس�
#include "stdio.h"
void main()
{
	int a,b,c,d,i,space,enter;
	char v;
	i=0;a=b=c=d=space=enter=0;
	while(i<4)
	{
		v=getchar();
		switch(v)
		{
				case '1': 
					a++;
					break;
				case '2': 
					b++;
					break;
				case '3': 
					c++;
					break;
				case '4':
					d++;
					break;
				case ' ':
					space++;
					break;
				case '\n':
					enter++;
					break;

		}
		i++;
	}
	printf("%d,%d,%d,%d,�ո�%d���س�%d\n",a,b,c,d,space,enter);
}
