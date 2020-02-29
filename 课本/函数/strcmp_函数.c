#include "stdio.h"
int strcmp(char str1[],char str2[])
{
	int i=0;
	while(str1[i]!='\0')
	{
		if(str1[i]!=str2[i])
		
			if(str1[i]>str2[i])
				return 1;
			else 
				return (-1);
		i++;
	}
	if(str2[i]=='\0')
		return  0;
	else return (str1[i]>str2[i]?1:(-1));
}
void main ()
{
	char a[]="hello",b[]="world";
	int n;
	n=strcmp(a,b);
	printf("%d",n);
}