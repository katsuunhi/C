#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

/*全局变量声明*/
int TNN;
int NFIN;
int NFRN;
int NOR;

float *XCN;
float *YCN;
int *BNR;
int *ENR;
float *TSR;

int *NWL;
float *XCL;
float *YCL;

float **LCS;
float *DON;
float *IFR;

/*子函数声明*/
void PHRead();
FILE *read_file();
void PHInput();
float **PHBuildTotalStif();
void PHLCosSin(int k);
void PHBuildUnitStif(int k,float us[2][2]);
int *PHI0J0(int k);
float *PHBuildLoadVector();
void PHCholesky(float **a,float *b,float *x,int n);

void PHRodForce();
void PHaaa();
void PHPrint();

void main()
{
	FILE *fp;
	char file_name[50];
	char value=0;
	float **kk,*pp;
	printf("欢迎使用平面桁架结构求解器！\n");
	printf("请输入文本文件名：\n");
    scanf("%s",file_name);
	getchar();
	printf("是否开始对结构节点位移、杆件内力进行计算？(Y/N)\n");
	scanf("%c",&value);
	if(value=='y'||value=='Y')			/*选择是否运行程序*/
	{
		fp=read_file(file_name);
		PHRead(fp);
		kk=PHBuildTotalStif();			/*总刚度阵计算，将其指针赋给kk*/
		pp=PHBuildLoadVector();			/*载荷向量计算，将其指针赋给pp*/
		PHCholesky(kk,pp,DON,2*NFRN);	/*改进的平方根法求位移，结果放在DON中*/
		PHRodForce();					/*计算杆件内力*/
		fclose(fp);
		PHPrint();						/*结构参数以及计算结果的输出*/
		getch();						/*防止程序运行结束后立即关闭*/
	}
}
//文件名调用程序
FILE *read_file(char*file_name)
{
	FILE *fp;
	//char c;
	//int i,j;
	//fp=fopen("structure_data.txt","r");
    fp=fopen(file_name,"r");
	return fp;
}
void PHRead(FILE *fp)
{
	//FILE *fp;
	char c;
	int i,j;
	fseek(fp,10L,0);
	fscanf(fp,"%d",&TNN);
	fseek(fp,14L,1);
	fscanf(fp,"%d",&NFIN);
	fseek(fp,10L,1);
	fscanf(fp,"%d",&NOR);
	fseek(fp,2L,1);
	NFRN=TNN-NFIN;
	XCN=(float *)calloc(TNN,sizeof(float));
	YCN=(float *)calloc(TNN,sizeof(float));
	BNR=(int *)calloc(NOR,sizeof(int));
	ENR=(int *)calloc(NOR,sizeof(int));
	TSR=(float *)calloc(NOR,sizeof(int));
	NWL=(int *)calloc(TNN,sizeof(int));
	XCL=(float *)calloc(TNN,sizeof(int));
	YCL=(float *)calloc(TNN,sizeof(int));
	DON=(float *)calloc(2*NFRN,sizeof(float));
	for(i=0;i<8;i++)
	{
		fseek(fp,11L,1);
		j=0;
		do
		{
			switch(i)
			{
			case 0:fscanf(fp,"%f",&XCN[j]);break;
			case 1:fscanf(fp,"%f",&YCN[j]);break;
			case 2:fscanf(fp,"%d",&BNR[j]);break;
			case 3:fscanf(fp,"%d",&ENR[j]);break;
			case 4:fscanf(fp,"%f",&TSR[j]);break;
			case 5:fscanf(fp,"%d",&NWL[j]);break;
			case 6:fscanf(fp,"%f",&XCL[j]);break;
			case 7:fscanf(fp,"%f",&YCL[j]);break;
			}
			fscanf(fp,"%c",&c);
			j++;
		}while(c!='\n');
	}
}
float **PHBuildTotalStif()
{
	float **kk,us[2][2];//kk为总刚度阵，us为单元刚度阵分块
	int i,j,k,m,n,*p;

	kk=(float **)calloc(2*NFRN,sizeof(float *));
	for(i=0;i<2*NFRN;i++)
		*(kk+i)=(float *)calloc(2*NFRN,sizeof(float));

    for(i=0;i<2*NFRN;i++)
		for(j=0;j<2*NFRN;j++)
			kk[i][j]=0;

	LCS=(float **)calloc(3,sizeof(float *));

	for(i=0;i<3;i++)
		*(LCS+i)=(float *)calloc(NOR,sizeof(float));
	for(k=0;k<NOR;k++)
	{
		PHLCosSin(k+1);
		PHBuildUnitStif(k,us);
		p=PHI0J0(k+1);
		for(i=0;i<2;i++)
		{
			if(p[i]>=0)
			{
				for(m=0;m<2;m++)
					for(n=0;n<2;n++)
						kk[p[i]+m][p[i]+n]+=us[m][n];
			}
		}
		if(p[0]>=0&&p[1]>=0)
		{
			for(i=0;i<2;i++)
			{
				for(m=0;m<2;m++)
					for(n=0;n<2;n++)
						kk[p[i]+m][p[1-i]+n]-=us[m][n];
			}
		}
	}
	return kk;
}
void PHLCosSin(int k)
{
   int i,j;
   k--;
   i=BNR[k]-1;
   j=ENR[k]-1;
   LCS[1][k]=XCN[j]-XCN[i];
   LCS[2][k]=YCN[j]-YCN[i];
   LCS[0][k]=sqrt(LCS[1][k]*LCS[1][k]+LCS[2][k]*LCS[2][k]);
   LCS[1][k]/=LCS[0][k];
   LCS[2][k]/=LCS[0][k];
}
void PHBuildUnitStif(int k,float us[2][2])
{
    int i,j;
    float rd;
    rd=TSR[k]/LCS[0][k];
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            us[i][j]=LCS[i+1][k]*LCS[j+1][k]*rd;
}

int *PHI0J0(int k)
{
	int bl,br,ij[2];
	bl=BNR[k-1];
	br=ENR[k-1];
	ij[0]=2*(bl-NFIN-1);
	ij[1]=2*(br-NFIN-1);
	return ij;
}
float *PHBuildLoadVector()
{
	int i;
	float *pp;
	pp=(float *)calloc(2*NFRN,sizeof(float));

	for(i=0;i<2*NFRN;i++)
		pp[i]=0;
	i=0;
	while(NWL[i]!=0)
	{
		pp[2*(NWL[i]-NFIN-1)]=XCL[i];
		pp[2*(NWL[i]-NFIN-1)+1]=YCL[i];
		i++;
	}
	return pp;
}

void PHCholesky(float **A,float *b,float *x,int n)
{
	int i,j,k;
	float s,**L,*D,*y;
	L=(float **)calloc(n,sizeof(float *));
	for(i=0;i<n;i++)
		*(L+i)=(float *)calloc(n,sizeof(float));
	D=(float *)calloc(n,sizeof(float));
	y=(float *)calloc(n,sizeof(float));

	for(i=0;i<n;i++)
		L[i][i]=1;
	D[0]=A[0][0];
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			s=0;
			for(k=0;k<j;k++)
				s=s+L[i][k]*D[k]*L[j][k];
			L[i][j]=(A[i][j]-s)/D[j];
		}
		s=0;
		for(k=0;k<i;k++)
			s=s+L[i][k]*L[i][k]*D[k];
		D[i]=A[i][i]-s;
	}
	y[0]=b[0];
	for(i=1;i<n;i++)
	{
		s=0;
		for(k=0;k<i;k++)
			s=s+L[i][k]*y[k];
		y[i]=b[i]-s;
	}
	x[n-1]=y[n-1]/D[n-1];
	for(i=n-2;i>=0;i--)
	{
		s=0;
		for(k=i+1;k<n;k++)
			s=s+L[k][i]*x[k];
		x[i]=y[i]/D[i]-s;
	}
}

void PHRodForce()
{
	int i,j,k,*p;
	float d1[2],d2[2],rd;
	IFR=(float *)calloc(NOR,sizeof(float));
	for(k=0;k<NOR;k++)
	{
		p=PHI0J0(k+1);
		i=p[0];
		j=p[1];
		if(i<0)
			d1[0]=d1[1]=0;
		else
		{
			d1[0]=DON[i];
			d1[1]=DON[i+1];
		}
		d2[0]=DON[j];
		d2[1]=DON[j+1];
		rd=TSR[k]/LCS[0][k];
		IFR[k]=rd*(LCS[1][k]*(d2[0]-d1[0])+LCS[2][k]*(d2[1]-d1[1]));
	}
}

void PHaaa()
{
	printf("--------------------------------------------------------------------------\n");
}

void PHPrint()
{
	int i,*p=NWL,n;
	FILE *fpWrite=fopen("result.txt","w"); 
	printf("\t\t\t\t平面桁架结构计算\n");

	PHaaa();
	printf("\t节点总数=%d\t固定节点数=%d\t可动节点数=%d\t杆件数=%d\n",TNN,NFIN,NFRN,NOR);
	PHaaa();
	printf("\t节点号\t\tX坐标\t\tY坐标\n");
	for(i=1;i<=TNN;i++)
		printf("\t%d\t\t%5.4f\t\t%5.4f\n",i,XCN[i-1],YCN[i-1]);
	PHaaa();
	printf("\t杆件号\t\t始端节点号\t末端节点号\t抗拉刚度EA\n");
	for(i=1;i<=NOR;i++)
		printf("\t%d\t\t%d\t\t%d\t\t%5.4f\n",i,BNR[i-1],ENR[i-1],TSR[i-1]);
	PHaaa();
	printf("\t荷载节点号\tX分量\t\tY分量\n");
	while(*p!=0)
	{
		p++;
	}
	n=p-NWL;
	for(i=1;i<=n;i++)
		printf("\t%d\t\t%5.4f\t\t%5.4f\n",NWL[i-1],XCL[i-1],YCL[i-1]);
	PHaaa();
	printf("计算结果\t节点位移输出:\n");
	PHaaa();
	printf("\t节点号\t\t位移X分量\t位移Y分量\n");
	for(i=0;i<NFRN;i++)
		printf("\t%d\t\t%5.7f\t%5.7f\n",NFIN+i+1,DON[2*i],DON[2*i+1]);
	PHaaa();
	printf("计算结果\t杆件内力输出:\n");
	PHaaa();
	printf("\t杆件号\t\t截面系数EA\t杆长l\t\t杆件内力\n");
	for(i=1;i<=NOR;i++)
		printf("\t%d\t\t%5.4f\t%5.4f\t\t%5.7f\n",i,TSR[i-1],LCS[0][i-1],IFR[i-1]);
	PHaaa();
	printf("\n\t\t\t\t感谢您的使用！\n\n\n\n\n\n\n");
	    
	fprintf(fpWrite,"\t节点号\t\t位移X分量\t位移Y分量\n");
	for(i=0;i<NFRN;i++)          
		fprintf(fpWrite,"\t%d\t\t%5.7f\t%5.7f\n",NFIN+i+1,DON[2*i],DON[2*i+1]);
    fprintf(fpWrite,"\t杆件号\t\t截面系数EA\t杆长l\t\t杆件内力\n");
	for(i=1;i<=NOR;i++)
	    fprintf(fpWrite,"\t%d\t\t%5.4f\t%5.4f\t\t%5.7f\n",i,TSR[i-1],LCS[0][i-1],IFR[i-1]);
      fclose(fpWrite);  
}