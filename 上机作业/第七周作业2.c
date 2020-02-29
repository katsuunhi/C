#include "stdio.h"
#include "string.h"

int main ()
{
	char ch[3][20],str[20];
	int i,k;
	for(i=0;i<=2;i++)
		gets(ch[i]);
	strcmp(ch[0],ch[1])<0?strcpy(str,ch[0]):strcpy(str,ch[1]);
	if(strcmp(ch[2],str)<0)
		strcpy(str,ch[2]);
	printf("%s",str);
	return 0;
}