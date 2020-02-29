//字符型数据会识别空格和回车，所以输入的时候不用按空格和回车
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
	printf("%d,%d,%d,%d,空格%d，回车%d\n",a,b,c,d,space,enter);
}
