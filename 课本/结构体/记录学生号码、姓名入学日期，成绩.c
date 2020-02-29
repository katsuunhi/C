#include <stdio.h>
struct date
{
	int year;
	int month;
	int day;
};
struct std
{
	int num;
	char name[20];
	struct date ent;
	float score;
}s[100];
int main ()
{
	int i;
	for(i=0;i<1;i++)
	{
		printf("input number:");
		scanf("%d",&s[i].num);
		printf("input name:");
		scanf("%s",&s[i].name);
		printf("input date:");
		scanf("%d %d %d",&s[i].ent.year,&s[i].ent.month,&s[i].ent.day);
		printf("input score:");
		scanf("%f",&s[i].score);
	}
	printf("number       name   year month  day  score\n");
	for(i=0;i<1;i++)
	{
		printf("%5d",s[i].num);
		printf("%10s",s[i].name);		
		printf("%5d",s[i].ent.year);		
		printf("%5d",s[i].ent.month);
		printf("%5d",s[i].ent.day);
		printf("%8f\n",s[i].score);
	}
}