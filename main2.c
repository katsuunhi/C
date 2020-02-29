#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include<math.h>

/*ȫ�ֱ�������*/

int TNN;    //�ڵ�����/total number of nodes
int NFIN;   //�̶��ڵ���/number of fixed nodes
int NFRN;    //�ɶ��ڵ���/number of free nodes
int NOR;    //�˼���/number of rods

float *XCN;     //�ڵ�x���������/X coordinate of nodes
float *YCN;		//�ڵ�y���������/Y coordinate of nodes
int *BNR;       //�˼�ʼ�˽ڵ��/the beginning node number of rods
int *ENR;       //�˼�ĩ�˽ڵ��/the end node number of rods
float *TSR;     //�˼������ն�EA/tensile stiffness of rods

int *NWL;       //�����غɵĽڵ��/node with load
float *XCL;       //�ڵ��غ�x�������/X component of the load
float *YCL;     //�ڵ��غ�x�������/X component of the load

float **LCS;    //�˼��ĳ��ȡ�������Һ��������
float *DON;     //�ڵ�λ�Ʒ���/displacement of nodes
float *IFR;     //�˼�����/innernal forces of rods

/*�Ӻ�������*/
//void PHRead();                      //���ı��ļ��ж�ȡ����
float **PHBuildTotalStif();         //�鼯�ܸն���
void PHLCosSin(int k);              //��˼��ĳ��ȡ�������Һ��������
void PHBuildUnitStif(int k,float us[2][2]);   //�󵥸��˼��ĵ�Ԫ�ն���
int *PHI0J0(int k);     //�ڵ�Ժź���
float *PHBuildLoadVector();     //�鼯�غ�����
void PHCholesky(float **a,float *b,float *x,int n);     //�Ľ���ƽ������ⷽ����
void PHRodForce();      //���˼�����
void PHaaa();           //��ʽ�������
void PHPrint();         //����������


FILE *read_file(char *file_name)
{
	FILE *fp;       //�����ļ�ָ��
    
    fp=fopen(file_name,"r"); //"structure_data.txt","r"); 
       //Ϊ��ȡ���ݴ��ı��ļ�
    return fp;
}


void main()
{
	FILE *fp;
	char  file_name[20];
	
    char value=0;       //����û�������ַ�

    float **kk,*pp;     //kkΪָ���ܸն����ָ�룬ppΪָ���غ�������ָ��
    scanf("%s",file_name);
    getchar();
    printf("��ӭʹ��ƽ������������\n");
    printf("�Ƿ�ʼ�Խṹ�ڵ�λ�ơ��˼��������м���?(Y/N):");
    scanf("%c",&value);         //�û�������ʾѡ�������ַ�
    PHaaa();                    //��������
    printf("\n\n");
    if(value=='y'||value=='Y');  //ѡ��y����y'���м���
    {

    	if(fp = read_file(file_name))
    		printf("��ȡ�ļ��ɹ�");
        PHRead(fp);	                 //�������ļ���������

        //kk=PHBuildTotalStif();  //�鼯�ܸն��󲢽�ָ�븳��kk
        //pp=PHBuildLoadVector(); //�鼯�غ���������ָ�븳��pp
        //PHCholesky(kk,pp,DON,2*NFRN);   //�Ľ���ƽ��������ڵ�λ�ƣ�������DON��
        //PHRodForce();           //����˼�����
        //PHPrint();             //��������Լ������������
    }

}
void PHRead(FILE *fp)
{
//    FILE *fp;       //�����ļ�ָ��
    char c;         //�����ʱ���ַ�������
    int i,j;        //ѭ�����Ʊ���
//    fp=fopen("structure_data.txt","r");     //Ϊ��ȡ���ݴ��ı��ļ�

    fseek(fp,10L,0);                        //��fp��ָλ�ôӳ�ʼλ�ú���10���ֽ�
    fscanf(fp,"%d",&TNN);                   //��ȡfpָ����������ݣ����TNN��
    fseek(fp,14L,1);                        //��fp��ָλ�ôӵ�ǰλ�ú���14���ֽ�
    fscanf(fp,"%d",&NFIN);                    //��ȡfpָ����������ݣ����NFTN��
    fseek(fp,10L,1);                        //��fp��ָλ�ôӵ�ǰλ�ú���10���ֽ�
    fscanf(fp,"%d",&NOR);                   //��ȡfpָ����������ݣ����NOR��
    fseek(fp,2L,1);                      //��fp��ָλ�ôӵ�ǰλ�ú���2���ֽ�
    NFRN=TNN-NFIN;  printf("\n%d\n%d\n%d\n%d\n",TNN,NFIN,NOR,NFRN);                        //����ɶ��ڵ�
    XCN=(float *)calloc(TNN,sizeof(float));     //ΪX��N����TNN�����ȵ���float�������ڴ�ռ䣬��ͬ
    YCN=(float *)calloc(TNN,sizeof(float));
    BNR=(int *)calloc(NOR,sizeof(int));
    ENR=(int *)calloc(NOR,sizeof(int));
    TSR=(float *)calloc(NOR,sizeof(int));
    NWL=(int *)calloc(TNN,sizeof(int));
    XCL=(float *)calloc(TNN,sizeof(int));
    YCL=(float *)calloc(TNN,sizeof(int));
    DON=(float *)calloc(2*NFRN,sizeof(float));
     
    
    for(i=0;i<8;i++)            //�ֱ��ȡ8�����ݴ����8���������
    {
        fseek(fp,11L,1);        //��fp��ָλ�ôӵ�ǰλ�ú���11���ַ�
        j=0;             //����ָ�꣬��ÿ�����ݵĵ�һ�����ݿ�ʼ
        do
        {
            switch(i)           //��switch�����ƶԸ������ݵĶ�ȡ
            {
                case 0:fscanf(fp,"%f",&XCN[j]);break;   //i=0ʱ��ȡfpָ��ĸ��������ݴ����ָ��Ϊj��XCN�����У�����swtich��䣬��ͬ
                case 1:fscanf(fp,"%f",&YCN[j]);break;
                case 2:fscanf(fp,"%d",&BNR[j]);break;
                case 3:fscanf(fp,"%d",&ENR[j]);break;
                case 4:fscanf(fp,"%f",&TSR[j]);break;
                case 5:fscanf(fp,"%d",&NWL[j]);break;
                case 6:fscanf(fp,"%f",&XCL[j]);break;
                case 7:fscanf(fp,"%f",&YCL[j]);break;
            }
            printf("BNR:\n%d\n",BNR[1]);
            fscanf(fp,"%c",&c);    //��ȡÿ�����ݺ�Ķ��Ż��з�
            j++;                    //����ָ���Լ�
        }while(c!='\n');           //����ȡ�����ݺ��治�ǻ��з��������ȡ
    }
    printf("PHREAD()����");
}
float **PHBuildTotalStif()
{
    float **kk,us[2][2];    //kkΪ�ܸնȾ���usΪ��Ԫ�ն���ֿ�
    int i,j,k,m,n,*p;       //i,j,m,nΪѭ�����Ʊ�����kΪ�˼�������
    kk=(float **)calloc(2*NFRN,sizeof(float *));	//�����������Ϊkk�����ά�ڴ�ռ�
    for(i=0;i<2*NFRN;i++)
        *(kk+i)=(float *)calloc(2*NFRN,sizeof(float));
    for(i=0;i<2*NFRN;i++)	//������������kkָ����ܸն�������
        for(j=0;j<2*NFRN;j++)
            kk[i][j]=0;
    LCS=(float **)calloc(3,sizeof(float *));	//�����������Ϊ��Ÿ˼����β�����LCS�����ά�ڴ�ռ�
    for(i=0;i<3;i++)
        *(LCS+i)=(float *)calloc(NOR,sizeof(float));
    for(k=0;k<NOR;k++)      //kΪ�˼������ţ���ÿһ���˼�ѭ������װ�ܸն���
    {
         PHLCosSin(k+1);   //����˼��ļ��β���
		 PHBuildUnitStif(k,us);   //���������Ϊk�ĸ˼��ĵ�Ԫ�ն���ܿ죬�����us��
		 p=PHI0J0(k+1);     //���������Ϊk�ĸ˼��˵�Ժ�λ�ã������pָ�������
		 for(i=0;i<2;i++)   //�Ը˼����˵��Ӧ�����ԽǷ���λ�ý��е���
		 {
			 if(p[i]>=0)
			 {
				for(m=0;m<2;m++)
					for(n=0;n<2;n++)
						kk[p[i]+m][p[i]+n]+=us[m][n];
				                         //��us�е��ĸ�Ԫ�ص��෴������Ӧλ�ý��е���
			 }
		 }
		 if(p[0]>=0&&p[1]>=0)          //��������˵�����˵���ɶ�������
		 {
			 for(i=0;i<2;i++)          //�Ը˼����˵��Ӧ�ķ����ԽǷ���λ�õ���
			 {
				 for(m=0;m<2;m++)
					 for(n=0;n<2;n++)
						 kk[p[i]+m][p[1-i]+n]-=us[m][n];
					                   //��us�е��ĸ�Ԫ�ص��෴������Ӧλ�ý��е���
			 }

		 }
    }
    return kk;//�����ܸն��������ָ��
}
void PHLCosSin(int k) //kΪʵ�ʱ��
{
	int i,j;
	k--;         //k�Լ�����Ϊ����˼���
	i=BNR[k]-1; //i��Ÿ˼���ʼ�˽ڵ��Ӧ�����е�����ָ��
	j=ENR[k]-1; //j��Ÿ˼���ĩ�˽ڵ��Ӧ�����е�����ָ��
	LCS[1][k]=XCN[j]-XCN[i];   //�˼�ʼĩ�˽ڵ�x����֮��
	LCS[2][k]=YCN[j]-YCN[i];   //�˼�ʼĩ�˽ڵ�y����֮��
	LCS[0][k]=sqrt(LCS[1][k]*LCS[1][k]+LCS[2][k]*LCS[2][k]); //��˼�����
	LCS[1][k]/=LCS[0][k];      //��˼��������ֵ
	LCS[2][k]/=LCS[0][k];      //��˼��������ֵ
}
void PHBuildUnitStif(int k ,float us[2][2]) //kΪ�˼���ţ�usΪ��Ԫ�ն���ֿ�
{
	int i,j;                 //i��jΪѭ�����Ʊ���
	float rd;               //rd��ſ����ն�ϵ��
	rd=TSR[k]/LCS[0][k];   //���㿹���ն�ϵ��
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			us[i][j]=LCS[i+1][k]*LCS[j+1][k]*rd; //����us�и�Ԫ��ֵ����ֵ
}
int *PHI0J0(int k)  //kΪ�˼���ʵ�ʱ��
{
	int bl,br,ij[2];
	bl=BNR[k-1];  //bl��Ÿ˼���ʼ�˽ڵ��
	br=ENR[k-1];  //br��Ÿ˼���ĩ�˽ڵ��
	ij[0]=2*(bl-NFIN-1); //��ʼ�˽ڵ����ܸն����ж�Ӧ��λ�ñ�Ŵ����ij������
	ij[1]=2*(br-NFIN-1); //��ĩ�˽ڵ����ܸն����ж�Ӧ��λ�ñ�Ŵ����ij������
	return ij; //����ij����ָ��
}
float *PHBuildLoadVector()
{
	int i,n;   //iΪѭ�����Ʊ�����nΪ��ͨ����
	float *pp; //pp����غ�����
	pp=(float *)calloc(2*NFRN,sizeof(float));  //Ϊpp����2*NFRN�����ȵ���float�������ڴ�ռ�
	for(i=0;i<2*NFRN;i++)  //�غ���������
		pp[i]=0;
	i=0;                   //ѭ����������
	while(NWL[i]!=0);  //��NWL��ָ��Ϊi��Ԫ�ز�Ϊ�㣬��ִ���������
	{
		pp[2*(NWL[i]-NFIN-1)]=XCL[i]; //�����i���غ�x������pp�еĶ�Ӧλ��
		pp[2*(NWL[i]-NFIN-1)+1]=YCL[i];    //����i���غɵ�y�������ӵ�pp��Ӧλ��
		i++;             //ѭ�������Լ�
	}
	return pp;           //�����غɱ�������ָ��
}
void PHCholesky(float **A,float *b,float *x,int n)  //AΪ�Գ�ϵ����bΪ����������xΪδ֪��������nΪά��
{
	int i,j,k;          //ѭ�����Ʊ���
	float s,**L,*D,*y;  //sΪ�м������L��DΪ�ֽ����yΪ�м����
	L=(float **)calloc(n,sizeof(float *));
	                                 //�����������Ϊkk�����λ�ڴ�ռ�
	for(i=0;i<n;i++)
		*(L+i)=(float *)calloc(n,sizeof(float));
	D=(float *)calloc(n,sizeof(float));
	                           //ΪD����n�����ȵ���float�������ڴ�ռ�
	y=(float *)calloc(n,sizeof(float));
                               //Ϊy����n�����ȵ���float�������ڴ�ռ�
	for (i=0;i<n;i++)
		L[i][i]=1;             //L��ʼ��
	/*��A�ֽ�ΪLDL(t)*/
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
    /*��Ly=b���y*/
    y[0]=b[0];
    for(i=1;i<n;i++)
    {
        s=0;
        for(k=0;k<i;k++)
            s=s+L[i][k]*y[k];
        y[i]=b[i]-s;
     }
     /*��DL(t)x=y���x*/
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
    int i,j,k,*p;        //i,jΪ��ͨ������kΪ�˼������ţ�
                         //pΪ��Ÿ˶˽ڵ�Ժ�λ�õ������ָ��
    float d1[2],d2[2],rd;//d1,d2�ֱ�Ϊ�˼�ʼĩ�˵�λ�Ʒ�����rdΪ�˼������ն�ϵ��
    IFR=(float *)calloc(NOR,sizeof(float));
                         //ΪIFR����NOR�����ȵ���float�������ڴ�ռ�
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
        d2[1]=DON[j+1];  //��DON��ĩ�˽ڵ�λ�����ݸ���d2�����ݱ�Ź���ĩ�˽ڵ�ض�Ϊ�ɶ��ڵ㣩
        rd=TSR[k]/LCS[0][k];  //����˼��Ŀ����ն�
        IFR[k]=rd*(LCS[1][k]*(d2[0]-d1[0])+LCS[2][k]*(d2[1]-d1[1]));  //����˼�����
     }
}
void PHaaa()
{
    printf("");
}
void PHPrint()
{
    int i,*p=NWL,n;          //ָ��pָ��NWL�׵�ַ
    printf("\t\t\t\tƽ����ܽṹ����\n");
    PHaaa();
    printf("\t�ڵ�����=%d\t�̶��ڵ���=%d\t�ɶ��ڵ���=%d\t�˼���=%d\n",TNN,NFIN,NFRN,NOR);
    PHaaa();
    printf("\t�ڵ��\t\tX����\t\tY����\n");
    for(i=1;i<NOR;i++)
        printf("\t%d\t\t%5.4f\t\t%5.4f\n",i,XCN[i-1],YCN[i-1]);
    PHaaa();
    printf("\t�˼���\t\tʼ�˽ڵ��\tĩ�˽ڵ��\t�����ն�EA\n");
    for(i=1;i<=NOR;i++)
        printf("\t%d\t\t%d\t\t%d\t\t%5.4f\n",i,BNR[i-1],ENR[i-1],TSR[i-1]);
    PHaaa();
    printf("\t���ؽڵ��\tX����\t\tY����\n");
    while(*p!=0)
    {
        p++;
    }
    n=p-NWL;
    for(i=1;i<=n;i++)
        printf("\t%d\t\t%5.4f\t\t%5.4f\n",NWL[i-1],XCL[i-1],YCL[i-1]);
    PHaaa();
    printf("������\t �ڵ�λ�������\n");
    PHaaa();
    printf("\t�ڵ��\t\tλ��X����\tλ��Y����\n");
    for(i=1;i<NFRN;i++)
        printf("\t%d\t\t%5.7f\t%5.7f\n",NFIN+i+1,DON[2*i],DON[2*i+1]);
    PHaaa();
    printf("������\t�˼����������\n");
    PHaaa();
    printf("\t�˼���\t\t����ϵ��EA\t�˳�l\t\t�˼�����\n");
    for(i=1;i<=NOR;i++)
        printf("\t%d\t\t%5.4f\t%5.4f\t\t%5.7f\n",i,TSR[i-1],LCS[0][i-1],IFR[i-1]);
    PHaaa();
    printf("\n\t\t\t\t��л����ʹ�ã�\n\n\n\n\n\n\\n");
}


