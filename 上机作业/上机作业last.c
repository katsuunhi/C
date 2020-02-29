//可以叠加点餐，不能删除已选食品，食品序号从0开始


#include "stdio.h"
#include "windows.h"

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
////////////////////////////////////////////////////////////////////////////

void printCheck()
{
	int i;
	double all_price=0;
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

////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void inputorder()
{
	int num,test,temp;
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
	printCheck();
}

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


void deleteorder()
{
	int n,num;
	char test;
	while(1)
	{
		
		printf("请输入需要删除的食品序号:");
		scanf("%d",&n);
		printf("请输入需要删除的食品个数:");
		scanf("%d",&num);
		if(orderList[n].count==0)
			printf("删除失败，请确认已经点了此食品。。。");
		else
		{
			orderList[n].count-=num;
			orderList[n].price-=num*menuList[num].menuPrice;
		}
		printf("是否继续？（y or n）:");
		fflush(stdin);
		scanf("%c",&test);
		if(test=='n')
			break;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

void confirm()
{
	char test;
	while(1)
	{
		printf("请确认菜单(\n输入s查看订单\n输入a继续点餐\n输入d删除某些食品\n输入y打印账单并结束)\n");
		test=getchar();
		switch(test)
		{
		case 'y':
		case 'Y':
			printCheck();
			return;
		case 'a':
		case 'A':
			inputorder();
			break;
		case 'd':
		case 'D':
			deleteorder();
			break;
		case 's':
		case 'S':
			printCheck();
			break;
		default:printCheck();
			break;
	}

	}

}

void main()
{
	showMenu();
	Sleep(2000);
	inputorder();
	Sleep(2000);
	confirm();
	Sleep(2000);
	printCheck();
}



