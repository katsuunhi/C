#include <stdio.h>
#include <malloc.h>

int minof(int a[], int n){
	int i;
	int min = a[0];
	for(i = 1; i < n; i ++){
		if(min > a[i])
			min = a[i];
	}
	return min;
}

int main(){
	int *height;
	int i;
	int number;

	printf("11111:");
	scanf("%d",&number);
	height = (int*)malloc(number*sizeof(int));
	printf("22222222");
	for(i = 0; i < number; i ++){
		printf("1:");
		scanf("%d",&height[i]);
	}
	printf("3333333:%d", minof(height, number));
	
	return 0;
}