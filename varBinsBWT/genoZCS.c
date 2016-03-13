
/*
    geno operation

*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#include"genoZCS.h"
/********************************************************************************/
/*  Function : bwtScore
/*  Description : 对sequence进行bwt评分
/*  Calls :   无

*/
/*  Called By       :
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   指向序列的字符指针

*/
/*  Output     :

*/
/*  Return     :　　point
/*  others     :
*/
/********************************************************************************/
int getGenoLength(char* geno)
{

 char fileName[64];
    memset(fileName,0x00,sizeof(fileName));
    //fileName又终端输入
    /*
    int i=0;
    printf("Please input the file name:  m");
    while((filename[i]=getchar())!='\n')
    {
        i++;
    }
    filename[i]='\0';
    */
    //指定fileName
    strcat(fileName,"chr21.fa");

    //获取文件指针fp
    FILE* fp;
    char file[1024];
    memset(file,0x00,sizeof(file));
    strcat(file,"/home/zcs/software/NB/varBinsBWT/");
    strcat(file,fileName);
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("File %s can not be open.",file);
        return -1;
    }
    //获取文件长度
    fseek(fp,0,SEEK_END);
    int file_length=ftell(fp);
    printf("this file length is %d\n",file_length);
    fseek(fp,0,SEEK_SET);

    //
    char* test=(char*)malloc((file_length+1)*sizeof(char));
    memset(test,0x00,sizeof(test));
    //
    char tmp[51];
    memset(tmp,0x00,sizeof(tmp));
    while(!feof(fp))
    {
      fscanf(fp,"%s",tmp);
      strcat(test,tmp);
      memset(tmp,0x00,sizeof(tmp));
    }
    printf("%s\n",test);
	    free(test);


    //








}
/********************************************************************************/
/*  Function : bwtScore
/*  Description : 对sequence进行bwt评分
/*  Calls :   无

*/
/*  Called By       :
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   指向序列的字符指针

*/
/*  Output     :

*/
/*  Return     :　　point
/*  others     :
*/
/********************************************************************************/
char* cutLineBreaks_M(char* geno)
{
    int i=0,j=0,len=0;
    len = strlen(geno);
    printf("Before cut line breaks, the length of geno is %d.\n",len);
    char* genoM=(char*)malloc((len+1)*sizeof(char));
    for (i=0;i<=len;i++)
    {
        if (geno[i]!='\n')
        {
            genoM[j]=geno[i];
            j++;
        }

    }
    genoM[j]='\0';
    //too low ,,,
    /*
    for (i=0;i<=len-n;i++)
    {

        if (geno[i] == '\n')
        {
            for (j=i;j<=len-1-n;j++)
                geno[j]=geno[j+1];
            printf("%d\n",n);
            n++;
        }

    }
    */
    len=strlen(genoM);
    printf("After cut line breaks, the length of geno is %d.\n",len);
    free(geno);
    return genoM;
}
/********************************************************************************/
/*  Function : bwtScore
/*  Description : 对sequence进行bwt评分
/*  Calls :   无

*/
/*  Called By       :
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   指向序列的字符指针

*/
/*  Output     :

*/
/*  Return     :　　point
/*  others     :
*/
/********************************************************************************/
char* cutN_N(char* geno)
{
    int i=0,j=0,len=0;
    len = strlen(geno);
    printf("Before cut N, the length of geno is %d.\n",len);
    char* genoM=(char*)malloc((len+1)*sizeof(char));
    for (i=0;i<=len;i++)
    {
        if (geno[i]!='N')
        {
            genoM[j]=geno[i];
            j++;
        }

    }
    genoM[j]='\0';
    len=strlen(genoM);
    printf("After cut N, the length of geno is %d.\n",len);
    free(geno);
    return genoM;
}
/********************************************************************************/
/*  Function : bwtScore
/*  Description : 对sequence进行bwt评分
/*  Calls :   无

*/
/*  Called By       :
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   指向序列的字符指针

*/
/*  Output     :

*/
/*  Return     :　　point
/*  others     :
*/
/********************************************************************************/
//为了减少内存使用，直接对char*操作
//但，对其拷贝操作更加合适
void capitalToLowerCase(char* geno)
{
    int y=0;
    while(geno[y]!='\0')
    {   //wait for improvement
        if((geno[y]>=65)&&(geno[y]<=90))
        {
            geno[y]=geno[y]+32;
            //tail_column[y]=tail_column[y]+32;
        }
        y++;
    }
    //return geno;
}



/********************************************************************************/
/*  Function : bwtScore
/*  Description : 对sequence进行bwt评分
/*  Calls :   无

*/
/*  Called By       :
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   指向序列的字符指针

*/
/*  Output     :

*/
/*  Return     :　　point
/*  others     :
*/
/********************************************************************************/
char* getSequenceByFileName_M(char* fileName)
{
    FILE* fp;
    char file[1024];
    memset(file,0x00,sizeof(file));
    strcat(file,"/home/zcs/software/NB/varBinsBWT/");
    strcat(file,fileName);
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("File %s can not be open.",file);
        return -1;
    }
    //获取文件长度,对于基因序列
    fseek(fp,0,SEEK_END);
    int file_length=ftell(fp);
    printf("this file length is %d\n",file_length);
    fseek(fp,0,SEEK_SET);
    //
    char* test=(char*)malloc((file_length+1)*sizeof(char));
    memset(test,0x00,sizeof(test));
    fread(test,1000000,90,fp);
    test=cutLineBreaks_M(test);
    fclose(fp);
    //test=cutN(test);
    //return test;
    return test;
}

/********************************************************************************/
/*  Function : bwtScore
/*  Description : 对sequence进行bwt评分
/*  Calls :   无

*/
/*  Called By       :
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   指向序列的字符指针

*/
/*  Output     :

*/
/*  Return     :　　point
/*  others     :
*/
/********************************************************************************/

char* getBinsSequence_M(char* sequence,int sta,int ed)
{
    char* thisSequence=(char*)malloc((ed-sta+1)*sizeof(char));
    memset(thisSequence,0x00,sizeof(thisSequence));
    int i=0,j=0;
    int len=0;
    len=strlen(sequence);
    for (i=0;i<len;i++)
    {
        if((i>=sta)&&(i<ed))
        {
            thisSequence[j]=sequence[i];
            j++;
        }

    }

    thisSequence[j]='\0';
    return thisSequence;

}
/********************************************************************************/
/*  Function : bwtScore
/*  Description : 对sequence进行bwt评分
/*  Calls :   无

*/
/*  Called By       :
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   指向序列的字符指针

*/
/*  Output     :

*/
/*  Return     :　　point
/*  others     :
*/
/********************************************************************************/
int* getBins_M(char* binsName,int* binsSize)
{
    FILE* fp;
    char file[1024];
    memset(file,0x00,sizeof(file));
    strcat(file,"/home/zcs/software/NB/");
    strcat(file,binsName);
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("File %s can not be open.",file);
        return -1;
    }
    //binsLen
    int binsLen=0;
    long temp=0;
    while(!feof(fp))
    {
        fscanf(fp,"%d",&temp);
        binsLen++;
    }
    fseek(fp,0,SEEK_SET);
    int binsNum=binsLen-1;
    printf("The number of bins is %d\n",binsNum);
    *binsSize=binsNum;
    //get into memory
    //int bins[binsLen];函数栈会'被清空',故需从堆里申请内存
    int* bins=(int*)malloc(binsLen*sizeof(int));
    //printf("%s\n","aa");
    int pp=0;
    while(!feof(fp))
    {
      fscanf(fp,"%d",&bins[pp]);
      printf("%d :  %d\n",pp,bins[pp]);
      pp++;
    }
    //mark
    bins[binsLen-1]=NULL;
    //printf("%d\n",bins[binsLen-2]);
    return bins;

}

/********************************************************************************/
/*  Function : bwtScore
/*  Description : 对sequence进行bwt评分
/*  Calls :   无

*/
/*  Called By       :
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   指向序列的字符指针

*/
/*  Output     :

*/
/*  Return     :　　point
/*  others     :
*/
/********************************************************************************/
void outputVector(int* thisVector,int vectorSize,char* outputFileName)
{
    FILE* fp;
    char file[1024];
    memset(file,0x00,sizeof(file));
    strcat(file,"/home/zcs/software/NB/");
    strcat(file,outputFileName);
    fp=fopen(file,"w");
    int i;
    for(i=0;i<vectorSize;i++)
        fprintf(fp,"%d\n",thisVector[i]);
    fclose(fp);
}
