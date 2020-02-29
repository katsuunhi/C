#include<stdio.h>

int main(){

	long n = 20;
	long *p = &n;
	printf("address: 0x%x\n", p);
	printf("size of n: %d\n", sizeof(int));
	printf("size of pointer: %d\n", sizeof(p));


	return 0;
}