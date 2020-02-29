#include <stdio.h>
#include <math.h>

int main(){
	char a;
	int minute = 0;
	while(1){

		printf("Please input the time (minute): ");
		scanf("%d", &minute);
		getchar();
		if(minute <= 120)
			printf("You have use it for %d minutes, you should pay 1 yuan!\n", minute);
		else
			printf("You have use it for %d minutes,  you should pay %d yuan!\n", minute, (int)ceil(1 + (minute - 120)/30.0));
		printf("Please input e/E to exit! Press enter to continue");
		a = getchar();
		if(a == 'e' || a == 'E')
			break;
	}
	return 0;
}