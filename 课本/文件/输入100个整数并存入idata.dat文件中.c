#include "stdio.h"

int main ()
{
	FILE *fp;
	int data[100],i;
	for(i=0;i<=2;i++)
	{
		scanf("%d",&data[i]);
	}
	if((fp=fopen("idata.txt","w+"))==NULL)
		printf("can not open the file idata.dat");
	else
	{
		fwrite(data,2,100,fp);
		fclose(fp);
	}
	return 0;
}