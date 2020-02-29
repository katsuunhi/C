// 物理 化学  生物

// 张王李赵陈

// 物理：张王     化学： 张李赵      生物：李赵陈


#include<stdio.h>

int main(){
	int physics[2] = {1,2};
	int chemistry[3] = {1,3,4};
	int biology[3] = {3,4,5};
	int num = 0;
	int phy = 0;
	int che = 0;
	int bio = 0;

	for(phy; phy < 2; phy ++){	
		for(che = 0; che < 3; che ++){
			for(bio = 0; bio < 3; bio ++){

				if(physics[phy] != chemistry[che] && physics[phy] != biology[bio] && chemistry[che] != biology[bio]){
					printf("physics:%d\t chemistry:%d\t biology:%d\t\n", physics[phy], chemistry[che], biology[bio]);
					num ++;
					
				}
			}
		}
	}
	printf("\ncount:%d", num);
	return 0;
}