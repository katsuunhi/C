#include <stdio.h>

int main ()
{
	static char a[20],b[20];
	register int i,m;
	printf("Please input two strings:");
	gets(a);
	gets(b);
	for(i=0;i<=19;i++)
	{
		if(a[i]=='\0')
		{
			for(m=0;m<=19;m++)
			{
				a[i]=b[m];
				i++;
				if(b[m]=='\0')
				{
					break;
				}
			}
		}
	}
	printf("%s\n",a);
	return 0;
}