#include "stdio.h"
#include "string.h"
#define A 100
#define B 5
struct student
{
	int num;
	char name[10];
	float grade[B];
}info[A],temp;
void main()
{
	int i,j;
	static float a[B],b[A];
	char find[10];
	//输入数据
	for(i=0;i<A;i++)
	{
		printf("学号：");
		scanf("%d",&info[i].num);
		printf("姓名：");
		scanf("%s",info[i].name);
		printf("依次输入五门成绩：");
		for(j=0;j<B;j++)
		{
			scanf("%f",&info[i].grade[j]);
			a[i]+=info[i].grade[j];
		}
	}
	//平均分，单人
	printf("单人平均分：\n");
	for(i=0;i<A;i++)
		printf("%f\n",a[i]/B);
	//平均分，单科
	printf("单科平均分：\n");
	for(j=0;j<B;j++)
	{
		a[j]=0;
		for(i=0;i<A;i++)
			a[j]+=info[i].grade[j];
		printf("%f\n",a[j]/A);
	}
	//搜索
	printf("\n输入姓名搜索成绩：\n");
	getchar();
	gets(find);
	for(i=0;i<A;i++)
	if(strcmp(find,info[i].name)==0)
	{
		for(j=0;j<B;j++)
			printf("%f\n",info[i].grade[j]);
	}
	//排序
	printf("按成绩排序后的信息(按回车键查看)：\n");
	getchar();
	for(i=0;i<A-1;i++)
		for(j=0;j<A-i-1;j++)
			if(a[j]<a[j+1])
			{
				 temp=info[j];
				 info[j]=info[j+1];
				 info[j+1]=temp;
			}
	for(i=0;i<A;i++)
	{
		printf("姓名：%s\n",info[i].name);
		printf("学号：%d\n",info[i].num);
		printf("成绩：");
		for(j=0;j<B;j++)
			printf("%f\n",info[i].grade[j]);
		printf("\n");
	}

}



