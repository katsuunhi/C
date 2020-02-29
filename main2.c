#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include<math.h>

/*全局变量声明*/

int TNN;    //节点总数/total number of nodes
int NFIN;   //固定节点数/number of fixed nodes
int NFRN;    //可动节点数/number of free nodes
int NOR;    //杆件数/number of rods

float *XCN;     //节点x方向的坐标/X coordinate of nodes
float *YCN;		//节点y方向的坐标/Y coordinate of nodes
int *BNR;       //杆件始端节点号/the beginning node number of rods
int *ENR;       //杆件末端节点号/the end node number of rods
float *TSR;     //杆件抗拉刚度EA/tensile stiffness of rods

int *NWL;       //具有载荷的节点号/node with load
float *XCL;       //节点载荷x方向分量/X component of the load
float *YCL;     //节点载荷x方向分量/X component of the load

float **LCS;    //杆件的长度、倾角余弦和倾角正弦
float *DON;     //节点位移分量/displacement of nodes
float *IFR;     //杆件内力/innernal forces of rods

/*子函数声明*/
//void PHRead();                      //从文本文件中读取数据
float **PHBuildTotalStif();         //组集总刚度阵
void PHLCosSin(int k);              //求杆件的长度、倾角余弦和倾角正弦
void PHBuildUnitStif(int k,float us[2][2]);   //求单根杆件的单元刚度阵
int *PHI0J0(int k);     //节点对号函数
float *PHBuildLoadVector();     //组集载荷向量
void PHCholesky(float **a,float *b,float *x,int n);     //改进的平方根求解方程组
void PHRodForce();      //求解杆件内力
void PHaaa();           //格式输出函数
void PHPrint();         //结果输出函数


FILE *read_file(char *file_name)
{
	FILE *fp;       //定义文件指针
    
    fp=fopen(file_name,"r"); //"structure_data.txt","r"); 
       //为读取数据打开文本文件
    return fp;
}


void main()
{
	FILE *fp;
	char  file_name[20];
	
    char value=0;       //存放用户输入的字符

    float **kk,*pp;     //kk为指向总刚度阵的指针，pp为指向载荷向量的指针
    scanf("%s",file_name);
    getchar();
    printf("欢迎使用平面桁架求解器！\n");
    printf("是否开始对结构节点位移、杆件内力进行计算?(Y/N):");
    scanf("%c",&value);         //用户根据提示选择输入字符
    PHaaa();                    //输出间隔符
    printf("\n\n");
    if(value=='y'||value=='Y');  //选择‘y’或‘y'进行计算
    {

    	if(fp = read_file(file_name))
    		printf("读取文件成功");
        PHRead(fp);	                 //从数据文件读入数据

        //kk=PHBuildTotalStif();  //组集总刚度阵并将指针赋给kk
        //pp=PHBuildLoadVector(); //组集载荷向量并将指针赋给pp
        //PHCholesky(kk,pp,DON,2*NFRN);   //改进的平方根法求节点位移，结果存放DON中
        //PHRodForce();           //计算杆件内力
        //PHPrint();             //结果参数以及计算结果的输出
    }

}
void PHRead(FILE *fp)
{
//    FILE *fp;       //定义文件指针
    char c;         //存放临时的字符型数据
    int i,j;        //循环控制变量
//    fp=fopen("structure_data.txt","r");     //为读取数据打开文本文件

    fseek(fp,10L,0);                        //将fp所指位置从初始位置后移10个字节
    fscanf(fp,"%d",&TNN);                   //读取fp指向的整形数据，存放TNN中
    fseek(fp,14L,1);                        //将fp所指位置从当前位置后移14个字节
    fscanf(fp,"%d",&NFIN);                    //读取fp指向的整形数据，存放NFTN中
    fseek(fp,10L,1);                        //将fp所指位置从当前位置后移10个字节
    fscanf(fp,"%d",&NOR);                   //读取fp指向的整形数据，存放NOR中
    fseek(fp,2L,1);                      //将fp所指位置从当前位置后移2个字节
    NFRN=TNN-NFIN;  printf("\n%d\n%d\n%d\n%d\n",TNN,NFIN,NOR,NFRN);                        //计算可动节点
    XCN=(float *)calloc(TNN,sizeof(float));     //为X、N分配TNN个长度等于float变量的内存空间，下同
    YCN=(float *)calloc(TNN,sizeof(float));
    BNR=(int *)calloc(NOR,sizeof(int));
    ENR=(int *)calloc(NOR,sizeof(int));
    TSR=(float *)calloc(NOR,sizeof(int));
    NWL=(int *)calloc(TNN,sizeof(int));
    XCL=(float *)calloc(TNN,sizeof(int));
    YCL=(float *)calloc(TNN,sizeof(int));
    DON=(float *)calloc(2*NFRN,sizeof(float));
     
    
    for(i=0;i<8;i++)            //分别读取8组数据存放在8个数组变量
    {
        fseek(fp,11L,1);        //将fp所指位置从当前位置后移11个字符
        j=0;             //数组指标，从每组数据的第一个数据开始
        do
        {
            switch(i)           //用switch语句控制对各组数据的读取
            {
                case 0:fscanf(fp,"%f",&XCN[j]);break;   //i=0时读取fp指向的浮点型数据存放在指标为j的XCN数组中，跳出swtich语句，下同
                case 1:fscanf(fp,"%f",&YCN[j]);break;
                case 2:fscanf(fp,"%d",&BNR[j]);break;
                case 3:fscanf(fp,"%d",&ENR[j]);break;
                case 4:fscanf(fp,"%f",&TSR[j]);break;
                case 5:fscanf(fp,"%d",&NWL[j]);break;
                case 6:fscanf(fp,"%f",&XCL[j]);break;
                case 7:fscanf(fp,"%f",&YCL[j]);break;
            }
            printf("BNR:\n%d\n",BNR[1]);
            fscanf(fp,"%c",&c);    //读取每个数据后的逗号或换行符
            j++;                    //数组指标自加
        }while(c!='\n');           //若读取的数据后面不是换行符则继续读取
    }
    printf("PHREAD()结束");
}
float **PHBuildTotalStif()
{
    float **kk,us[2][2];    //kk为总刚度矩阵，us为单元刚度阵分块
    int i,j,k,m,n,*p;       //i,j,m,n为循环控制变量，k为杆件程序编号
    kk=(float **)calloc(2*NFRN,sizeof(float *));	//以下三行语句为kk申请二维内存空间
    for(i=0;i<2*NFRN;i++)
        *(kk+i)=(float *)calloc(2*NFRN,sizeof(float));
    for(i=0;i<2*NFRN;i++)	//以下三行语句对kk指向的总刚度阵清零
        for(j=0;j<2*NFRN;j++)
            kk[i][j]=0;
    LCS=(float **)calloc(3,sizeof(float *));	//以下三行语句为存放杆件几何参数的LCS申请二维内存空间
    for(i=0;i<3;i++)
        *(LCS+i)=(float *)calloc(NOR,sizeof(float));
    for(k=0;k<NOR;k++)      //k为杆件程序编号，对每一根杆件循环，组装总刚度阵
    {
         PHLCosSin(k+1);   //计算杆件的几何参数
		 PHBuildUnitStif(k,us);   //计算程序编号为k的杆件的单元刚度振奋快，存放在us中
		 p=PHI0J0(k+1);     //计算程序编号为k的杆件端点对号位置，存放在p指向的数组
		 for(i=0;i<2;i++)   //对杆件两端点对应的主对角方块位置进行叠加
		 {
			 if(p[i]>=0)
			 {
				for(m=0;m<2;m++)
					for(n=0;n<2;n++)
						kk[p[i]+m][p[i]+n]+=us[m][n];
				                         //对us中的四个元素的相反数按相应位置进行叠加
			 }
		 }
		 if(p[0]>=0&&p[1]>=0)          //若符合则说明两端点均可动并叠加
		 {
			 for(i=0;i<2;i++)          //对杆件两端点对应的费主对角方块位置叠加
			 {
				 for(m=0;m<2;m++)
					 for(n=0;n<2;n++)
						 kk[p[i]+m][p[1-i]+n]-=us[m][n];
					                   //对us中的四个元素的相反数按相应位置进行叠加
			 }

		 }
    }
    return kk;//返回总刚度阵的数组指针
}
void PHLCosSin(int k) //k为实际编号
{
	int i,j;
	k--;         //k自减，即为程序杆件号
	i=BNR[k]-1; //i存放杆件的始端节点对应程序中的数组指标
	j=ENR[k]-1; //j存放杆件的末端节点对应程序中的数组指标
	LCS[1][k]=XCN[j]-XCN[i];   //杆件始末端节点x坐标之差
	LCS[2][k]=YCN[j]-YCN[i];   //杆件始末端节点y坐标之差
	LCS[0][k]=sqrt(LCS[1][k]*LCS[1][k]+LCS[2][k]*LCS[2][k]); //求杆件长度
	LCS[1][k]/=LCS[0][k];      //求杆件倾角余弦值
	LCS[2][k]/=LCS[0][k];      //求杆件倾角正弦值
}
void PHBuildUnitStif(int k ,float us[2][2]) //k为杆件编号，us为单元刚度阵分块
{
	int i,j;                 //i、j为循环控制变量
	float rd;               //rd存放抗拉刚度系数
	rd=TSR[k]/LCS[0][k];   //计算抗拉刚度系数
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			us[i][j]=LCS[i+1][k]*LCS[j+1][k]*rd; //计算us中各元素值并赋值
}
int *PHI0J0(int k)  //k为杆件的实际编号
{
	int bl,br,ij[2];
	bl=BNR[k-1];  //bl存放杆件的始端节点号
	br=ENR[k-1];  //br存放杆件的末端节点号
	ij[0]=2*(bl-NFIN-1); //将始端节点在总刚度阵中对应的位置编号存放在ij数组中
	ij[1]=2*(br-NFIN-1); //将末端节点在总刚度阵中对应的位置编号存放在ij数组中
	return ij; //返回ij数组指针
}
float *PHBuildLoadVector()
{
	int i,n;   //i为循环控制变量，n为普通变量
	float *pp; //pp存放载荷向量
	pp=(float *)calloc(2*NFRN,sizeof(float));  //为pp分配2*NFRN个长度等于float变量的内存空间
	for(i=0;i<2*NFRN;i++)  //载荷向量清零
		pp[i]=0;
	i=0;                   //循环变量归零
	while(NWL[i]!=0);  //当NWL中指标为i的元素不为零，则执行以下语句
	{
		pp[2*(NWL[i]-NFIN-1)]=XCL[i]; //计算第i个载荷x分量在pp中的对应位置
		pp[2*(NWL[i]-NFIN-1)+1]=YCL[i];    //将第i个载荷的y分量叠加到pp相应位置
		i++;             //循环变量自加
	}
	return pp;           //返回载荷变量数组指针
}
void PHCholesky(float **A,float *b,float *x,int n)  //A为对称系数阵，b为常数向量，x为未知数向量，n为维数
{
	int i,j,k;          //循环控制变量
	float s,**L,*D,*y;  //s为中间变量，L、D为分解矩阵，y为中间变量
	L=(float **)calloc(n,sizeof(float *));
	                                 //以下三行语句为kk申请二位内存空间
	for(i=0;i<n;i++)
		*(L+i)=(float *)calloc(n,sizeof(float));
	D=(float *)calloc(n,sizeof(float));
	                           //为D申请n个长度等于float变量的内存空间
	y=(float *)calloc(n,sizeof(float));
                               //为y申请n个长度等于float变量的内存空间
	for (i=0;i<n;i++)
		L[i][i]=1;             //L初始化
	/*将A分解为LDL(t)*/
	D[0]=A[0][0];
	for(i=1;i<n;i++)
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
    /*由Ly=b求解y*/
    y[0]=b[0];
    for(i=1;i<n;i++)
    {
        s=0;
        for(k=0;k<i;k++)
            s=s+L[i][k]*y[k];
        y[i]=b[i]-s;
     }
     /*由DL(t)x=y求解x*/
     x[n-1]=y[n-1]/D[n-1];
     for(i=n-2;i>=0;i--);
     {
        s=0;
        for(k=i+1;k<n;k++)
            s=s+L[k][i]*x[k];
    	x[i]=y[i]/D[i]-s;
     }
}
void PHRodForce()
{
    int i,j,k,*p;        //i,j为普通变量，k为杆件程序编号，
                         //p为存放杆端节点对号位置的数组的指针
    float d1[2],d2[2],rd;//d1,d2分别为杆件始末端的位移分量，rd为杆件抗拉刚度系数
    IFR=(float *)calloc(NOR,sizeof(float));
                         //为IFR分配NOR个长度等于float变量的内存空间
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
        d2[1]=DON[j+1];  //将DON中末端节点位移数据赋给d2（根据编号规则末端节点必定为可动节点）
        rd=TSR[k]/LCS[0][k];  //计算杆件的抗拉刚度
        IFR[k]=rd*(LCS[1][k]*(d2[0]-d1[0])+LCS[2][k]*(d2[1]-d1[1]));  //计算杆件内力
     }
}
void PHaaa()
{
    printf("");
}
void PHPrint()
{
    int i,*p=NWL,n;          //指针p指向NWL首地址
    printf("\t\t\t\t平面桁架结构计算\n");
    PHaaa();
    printf("\t节点总数=%d\t固定节点数=%d\t可动节点数=%d\t杆件数=%d\n",TNN,NFIN,NFRN,NOR);
    PHaaa();
    printf("\t节点号\t\tX坐标\t\tY坐标\n");
    for(i=1;i<NOR;i++)
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
    printf("计算结果\t 节点位移输出：\n");
    PHaaa();
    printf("\t节点号\t\t位移X分量\t位移Y分量\n");
    for(i=1;i<NFRN;i++)
        printf("\t%d\t\t%5.7f\t%5.7f\n",NFIN+i+1,DON[2*i],DON[2*i+1]);
    PHaaa();
    printf("计算结果\t杆件内力输出：\n");
    PHaaa();
    printf("\t杆件号\t\t截面系数EA\t杆长l\t\t杆件内力\n");
    for(i=1;i<=NOR;i++)
        printf("\t%d\t\t%5.4f\t%5.4f\t\t%5.7f\n",i,TSR[i-1],LCS[0][i-1],IFR[i-1]);
    PHaaa();
    printf("\n\t\t\t\t感谢您的使用！\n\n\n\n\n\n\\n");
}


