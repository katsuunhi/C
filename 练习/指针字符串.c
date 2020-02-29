#include <stdio.h>
#include <windows.h>

int main ()
{
	int i;
	for(i=0;i<=100;i++)
	{
		if(i%3==0)
			system("color EC");
		if(i%3==1)
			system("color CF");
		if(i%3==2)
			system("color 54");
		Sleep(1000);
	}

	return 0;
}