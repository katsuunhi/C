#include "stdio.h"
#include "string.h"
#include "windows.h"

#define N 2            //ѧ����
#define M 2            //�γ���

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
			printf("������ѧ�ţ�");
			scanf("%d",&std_info[i].num);
			printf("������������");
			scanf("%s",std_info[i].name);
			printf("�������������ſγɼ���");
			for(j=0;j<M;j++)
			{
				scanf("%f",&std_info[i].grade[j]);
				std_ave[i]+=std_info[i].grade[j];
			}
		}
			printf("����¼��ɹ�\n");
			Sleep(2000);
}

void std_avef()
{
	for(i=0;i<N;i++)
			{
				printf("��%dλͬѧ��ƽ����Ϊ%f\n",i+1,std_ave[i]/M);
			}
	Sleep(2000);
}

void course_avef()
{
		/*���ſγ̵�ȫ��ѧ��ƽ����*/
		
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
				course_ave[i]+=std_info[j].grade[i];
		}
	}
	for(i=0;i<M;i++)
	{
		printf("��%d�ſγ̵�ȫ��ƽ����Ϊ%f\n",i,course_ave[i]/N);
	}
	Sleep(2000);
}

void searchf()
{
	getchar();
	printf("������������");
		gets(search);
	printf("��ѧ�������ųɼ��ֱ�Ϊ��\n");
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
	printf("\t����\tѧ��\t\t�ɼ�\t\t\n");
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
		printf("\n**********************\n*��ӭʹ������¼��ϵͳ*\n**********************\n�����룺\n1.��������\n2.��ʾÿ��ѧ����5�ųɼ�ƽ����\n3.��ʾÿ�ųɼ���ȫ��ƽ����\n4.�����������ҳɼ�\n5.��ʾ�������е�ѧ������\n0.�˳�ϵͳ\n");
		scanf("%d",&test);
		switch(test)
		{
		case 1:	
			input();
		break;
		/*   ����ѧ�����ſγ̵�ƽ����   */
		case 2:
			std_avef();
			break;
			/*���ſγ̵�ƽ���ɼ�*/
		case 3:
			course_avef();
			break;
		/*�����������ҳɼ�*/
		case 4:
			searchf();
			break;
			/*�ܳɼ���������*/
		case 5:
			output();
			break;
			/*�˳�ϵͳ*/
		case 0:
			printf("ллʹ�ã������˳�......\n");
			return 0;
		}
	}
}
