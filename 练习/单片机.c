#include "stdio.h"

int heart[34]={
DB ,FFH ,FFH ,E3H ,DDH, BEH, BFH ,BFH, BFH, DFH, EFH, F7H, FBH ,FDH, FEH ,FFH ,FFH,
DB ,FFH ,FFH ,C7H ,BBH ,7DH ,FDH ,FDH ,FDH, FBH ,F7H, EFH, DFH ,BFH, 7FH, FFH, FFH}

int main ()
{
	int i;
	for(i=0;i<=33;i++)
	printf("%d",heart[i]);
}