#include "stdio.h"
#include "string.h"
#include "windows.h"

#define N 2            //学生数
#define M 2            //课程数

int i,j,test,m;
static float std_ave[N],course_ave[M];
char search[10];

struct student
{
	int num,temp;
	char name[10];
	float grade[M];
}std_info[N];

void input()
{
	for(i=0;i<N;i++)
		{
			printf("请输入学号：");
			scanf("%d",&std_info[i].num);
			printf("请输入姓名：");
			scanf("%s",std_info[i].name);
			printf("请依次输入五门课成绩：");
			for(j=0;j<M;j++)
			{
				scanf("%f",&std_info[i].grade[j]);
				std_ave[i]+=std_info[i].grade[j];
			}
		}
			printf("数据录入成功\n");
			Sleep(2000);
}

void std_avef()
{
	for(i=0;i<N;i++)
			{
				printf("第%d位同学的平均分为%f\n",i+1,std_ave[i]/M);
			}
	Sleep(2000);
}

void course_avef()
{
		/*单门课程的全体学生平均分*/
		
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
				course_ave[i]+=std_info[j].grade[i];
		}
	}
	for(i=0;i<M;i++)
	{
		printf("第%d门课程的全班平均分为%f\n",i,course_ave[i]/N);
	}
	Sleep(2000);
}

void searchf()
{
	getchar();
	printf("请输入姓名：");
		gets(search);
	printf("该学生的五门成绩分别为：\n");
	for(i=0;i<N;i++)
	{
		if(strcmp(std_info[i].name,search)==0)
			for(j=0;j<M;j++)
				printf("%f\n",std_info[i].grade[j]);
	}
	Sleep(2000);
}

void output()
{	
	struct student temp;
	for(i=0;i<N-1;i++)
		
			for(j=0;j<N-i-1;j++)
				if(std_ave[j]<std_ave[j+1])
				{
					 temp=std_info[j];
					 std_info[j]=std_info[j+1];
					 std_info[j+1]=temp;
				}
	printf("\t姓名\t学号\t\t成绩\t\t\n");
	for(i=0;i<N;i++)
	{
		printf("%s\t",std_info[i].name);
		printf("%5d\t",std_info[i].num);
		for(j=0;j<M;j++)
		{
			printf("%5f ",std_info[i].grade[j]);
		}printf("\n");
	}
	Sleep(2000);
}

void main()
{
	while(1)
	{
		printf("\n**********************\n*欢迎使用数据录入系统*\n**********************\n请输入：\n1.输入数据\n2.显示每个学生的5门成绩平均分\n3.显示每门成绩的全班平均分\n4.输入姓名查找成绩\n5.显示降序排列的学生数据\n0.退出系统\n");
		scanf("%d",&test);
		switch(test)
		{
		case 1:	
			input();
		break;
		/*   单个学生五门课程的平均分   */
		case 2:
			std_avef();
			break;
			/*单门课程的平均成绩*/
		case 3:
			course_avef();
			break;
		/*输入姓名查找成绩*/
		case 4:
			searchf();
			break;
			/*总成绩降序排列*/
		case 5:
			output();
			break;
			/*退出系统*/
		case 0:
			printf("谢谢使用！正在退出......\n");
			return 0;
		}
	}
}
