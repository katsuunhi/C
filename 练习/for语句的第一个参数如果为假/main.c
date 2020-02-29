#include<stdio.h>

int main(){

	int i = 0;

	for(false; i < 0; i ++)
		printf("%d\n", i);


	return 0;

}

//第一个参数的真假与for的循环体的执行与否无关，但是初始化之后需要立刻执行条件表达式判断是否执行第一次循环