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
}                                    //�ٸ�������
void  ave (int a[][3],int n)        //�ٸ�������
{
	int i,j,sum,ave;
	for (i=0;i<n;i++)               //�ֺ�д���˶���
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
	printf("����n��ֵ:\n");     //�ٸ��ֺ�
	scanf("%d",&n);
	
         //
	
	printf("����ɼ�:\n");         //�ֺ�
	Input(score,n);
	printf("����ɼ�:\n");           //�ֺ�
	Show(score,n);
	
	printf("��%d��ѧ��ƽ���ɼ�Ϊ:%d\n",i,ave(scove,n));
	return 0;
}