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
	//��������
	for(i=0;i<A;i++)
	{
		printf("ѧ�ţ�");
		scanf("%d",&info[i].num);
		printf("������");
		scanf("%s",info[i].name);
		printf("�����������ųɼ���");
		for(j=0;j<B;j++)
		{
			scanf("%f",&info[i].grade[j]);
			a[i]+=info[i].grade[j];
		}
	}
	//ƽ���֣�����
	printf("����ƽ���֣�\n");
	for(i=0;i<A;i++)
		printf("%f\n",a[i]/B);
	//ƽ���֣�����
	printf("����ƽ���֣�\n");
	for(j=0;j<B;j++)
	{
		a[j]=0;
		for(i=0;i<A;i++)
			a[j]+=info[i].grade[j];
		printf("%f\n",a[j]/A);
	}
	//����
	printf("\n�������������ɼ���\n");
	getchar();
	gets(find);
	for(i=0;i<A;i++)
	if(strcmp(find,info[i].name)==0)
	{
		for(j=0;j<B;j++)
			printf("%f\n",info[i].grade[j]);
	}
	//����
	printf("���ɼ���������Ϣ(���س����鿴)��\n");
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
		printf("������%s\n",info[i].name);
		printf("ѧ�ţ�%d\n",info[i].num);
		printf("�ɼ���");
		for(j=0;j<B;j++)
			printf("%f\n",info[i].grade[j]);
		printf("\n");
	}

}



