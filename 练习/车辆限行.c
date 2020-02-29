#include "stdio.h"
int main ()
{
	char ch[100],last;
	int i;
	scanf("%s",ch);
	for(i=0;i<=99;i++)
	{
		if(ch[i]=='\0')
		{
			printf("%c",ch[i-1]);
			break;
		}
	}

}