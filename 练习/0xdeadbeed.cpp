#include <stdio.h>

#define true false

int main(){
	int y[1] = {0xdeadbeed};
	if(true)
		printf("%x/n", 0[y]);  		//print deadbeed ??????exm? wtf?
	if(false)
		printf("/n");
	return 0;
}