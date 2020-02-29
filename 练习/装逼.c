#include<stdio.h>
 void    Input(int a[][3],int n)
{
	int i,j; 
	for (i=0;i<n;i++)
	{
		for (j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
void Show(int a[][3],int n)
{
	int i,j; 
	for (i=0;i<n;i++)
	{
		for (j=0;j<3;j++)
		{
			printf("%d",a[i][j]);
		}
	}
}                                    //少个大括号
void  ave (int a[][3],int n)        //少个数组名
{
	int i,j,sum,ave;
	for (i=0;i<n;i++)               //分号写成了逗号
	{
		sum=0;
		for (j=0;j<3;j++)
		{
			sum=sum+a[i][3];
		}
		ave=sum/3;

	}
}

int main()
{
	int n;
	int score[100][3];   
	printf("输入n的值:\n");     //少个分号
	scanf("%d",&n);
	
         //
	
	printf("输入成绩:\n");         //分号
	Input(score,n);
	printf("输出成绩:\n");           //分号
	Show(score,n);
	
	printf("第%d的学生平均成绩为:%d\n",i,ave(scove,n));
	return 0;
}