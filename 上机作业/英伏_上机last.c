//���Ե��ӵ�ͣ�����ɾ����ѡʳƷ��ʳƷ��Ŵ�0��ʼ


#include "stdio.h"


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//char *menu[]={"Plain_Egg","Bacon","Muffin","Fruit_Basket","French_Toast","Coffee","Cereal","Tea"};
struct menuItemType
{
	char menuItem[20];
	double menuPrice;
};
struct order
{
	double price;
	int count;
}orderList[8];
struct menuItemType menuList[8]={"Plain_Egg",1.99,"Bacon",2.45,"Muffin",0.99,"Fruit_Basket",2.49,"French_Toast",1.99,"Coffee",0.50,"Cereal",0.69,"Tea",0.75};
////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void showMenu()
{
	int i;
	printf("*************************************\n");
	printf("*************************************\n");
	printf("*************************************\n");
	printf("\t\t�˵�\n\n");
	printf("���\t\tʳƷ\t\t�۸�\n");
	for(i=0;i<8;i++)
		printf("%d. %17s\t\t%lf\n",i,menuList[i].menuItem,menuList[i].menuPrice);
	printf("*************************************\n");
	printf("*************************************\n");
	printf("*************************************\n");
}

////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void printCheck()
{
	int num,i,test,temp;
	double all_price=0;
	printf("���ͣ�\n");
	while(1)
	{
		printf("������ʳƷ��ţ�");
		scanf("%d",&num);
		printf("�����������");
		if(orderList[num].count==0)
			scanf("%d",&orderList[num].count);
		else
		{
			scanf("%d",&temp);
			orderList[num].count+=temp;
		}
		orderList[num].price=menuList[num].menuPrice*orderList[num].count;
		getchar();
		printf("�Ƿ�Ҫ������ͣ��������롮y������");
		if((test=getchar())!='y'&&test!='Y')
			break;
	}
	printf("*****************************************\n");
	printf("*****************************************\n");
	printf("*****************************************\n");
	printf("\t\t\t�˵�\n\n\nʳƷ\t\t����\t\t����\t\t�۸�\n");	
	for(i=0;i<8;i++)
	{
		all_price+=orderList[i].price;
		printf("%-16s%lf\t%d\t\t%lf\n",menuList[i].menuItem,menuList[i].menuPrice,orderList[i].count,orderList[i].price);
	}
	all_price*=1.05;
	printf("\t\t\t\t�����ѣ�%.2lf������5%%��˰�ѣ�\n",all_price);

}

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void main()
{
	showMenu();
	printCheck();
}



