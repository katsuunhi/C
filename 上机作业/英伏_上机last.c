//可以叠加点餐，不能删除已选食品，食品序号从0开始


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
	printf("\t\t菜单\n\n");
	printf("序号\t\t食品\t\t价格\n");
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
	printf("请点餐：\n");
	while(1)
	{
		printf("请输入食品序号：");
		scanf("%d",&num);
		printf("请输入个数：");
		if(orderList[num].count==0)
			scanf("%d",&orderList[num].count);
		else
		{
			scanf("%d",&temp);
			orderList[num].count+=temp;
		}
		orderList[num].price=menuList[num].menuPrice*orderList[num].count;
		getchar();
		printf("是否还要继续点餐（继续输入‘y’）：");
		if((test=getchar())!='y'&&test!='Y')
			break;
	}
	printf("*****************************************\n");
	printf("*****************************************\n");
	printf("*****************************************\n");
	printf("\t\t\t账单\n\n\n食品\t\t单价\t\t个数\t\t价格\n");	
	for(i=0;i<8;i++)
	{
		all_price+=orderList[i].price;
		printf("%-16s%lf\t%d\t\t%lf\n",menuList[i].menuItem,menuList[i].menuPrice,orderList[i].count,orderList[i].price);
	}
	all_price*=1.05;
	printf("\t\t\t\t总消费：%.2lf（包含5%%的税费）\n",all_price);

}

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void main()
{
	showMenu();
	printCheck();
}



