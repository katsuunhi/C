//通过函数实现查找一串数组中的最大数以及它的个数，要求最大数用return返回，个数用形参带回

#include <stdio.h>

int main()
{
	int a[10] = {2, 3, 3, 2, 4, 5, 6, 6, 6, 6};
	int num;
	int max;
	max = f(a, 10, &num);
	printf("max: %d\nnum: %d\n", max, num);
	return 0;
}

int f(int a[], int n, int *num)
{
	int max = a[0];
	int i = 0;
	*num = 1;
	for(i = 1; i < n; i ++)
	{
		if(a[i] > max)
		{
			max = a[i];
			*num = 1;
		}
		else if(a[i] == max)
			(*num) ++;
	}
	return max;
}