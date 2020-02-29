#include "stdio.h"

void main (int argc,char *argv[])
{
	int i=0;
	while (argc>1)
	{
		++i;
		printf("%s\n",argv[i]);
		--argc;
	}
}