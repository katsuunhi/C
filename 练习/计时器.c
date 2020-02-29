#include "stdio.h"
#include "windows.h"
int main ()
{
	int i;

	for(i=0;i<=100;i++)
	{
		if(i%3==0)
			system("color 1e");
		if(i%3==1)
			system("color 98");
		if(i%3==2)
			system("color 56");
		printf("%d\r",i);
		Sleep(1000);
	}
	return 0;

}