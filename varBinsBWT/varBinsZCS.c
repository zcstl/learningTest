#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#include"bwtZCS.h"
#include"genoZCS.h"
#include"varBinsZCS.h"


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
void getVarBins(char* chrFileName,int bwtDestScore,char* outputBinsName)
{
    char* sequence;
    int sequenceLen=0;
    sequence=getSequenceByFileName_M(chrFileName);
    sequenceLen=strlen(sequence);
    int binsNumMax=sequenceLen/bwtDestScore+1+1;
    int binsNum=binsNumMax;
    //int bins[binsNumMax]={0};
    int* bins=(int*)malloc(binsNumMax*sizeof(int));
    int i=1;
    int rightInterval=bwtDestScore;
    bins[0]=0;
    //printf("%s\n","fff");
    for(;i<binsNumMax;i++)
    {
        rightInterval=getRightInterval(sequence,bins[i-1],bwtDestScore);
        //printf("%d\n",sizeof(rightInterval));
        //此处rightInterval与getRightInterval的rightInterval不同,值传递问题??bug.....
        //printf("22222222222The right Interval of this bin is %d\n.",rightInterval);
        bins[i]=rightInterval;
        if (rightInterval==sequenceLen)
            break;
    }
    //printf("%s\n","aaa");
    binsNum=i;
    FILE* fp;
    char file[1024];
    memset(file,0x00,sizeof(file));
    strcat(file,"/home/zcs/software/NB/varBinsBWT/");
    strcat(file,outputBinsName);
    fp=fopen(file,"w");
    for(i=0;i<binsNum;i++)
        fprintf(fp,"%d\n",bins[i]);
    fclose(fp);
    free(bins);
    free(sequence);
}

/********************************************************************************/
/*  Function : getRightInterval
/*  Description : 左闭右开，获取满足bwt评分的右区间位置
/*  Calls :   无

*/
/*  Called By       :
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   par1:序列； par2:左区间

*/
/*  Output     :　　　　右区间

*/
/*  Return     :　　　　右区间
/*  others     :
*/
/********************************************************************************/
int getRightInterval(char* sequence,int leftInterval,int bwtDestScore)
{
    int sequenceLen=strlen(sequence);
    int rightInterval=0;
    int score=0;
    int stepSize=5000;
    int scoreLeftInterval=bwtDestScore;
    int scoreRightInterval=bwtDestScore+stepSize;
    rightInterval=crossN(sequence,leftInterval);
    rightInterval=rightInterval+bwtDestScore;
    //printf("%s\n","ddd");
    if(rightInterval>=sequenceLen)
    {
        rightInterval=sequenceLen;
    }
    else
    {
        while(1)
        {
            //printf("%s\n","ccc");
            score=bwtScorePart(sequence,leftInterval,rightInterval);
            //printf("%s\n","ccc");
            printf("This score is  : %d\n",score);
            if((score>=scoreLeftInterval)&&(score<scoreRightInterval))
                break;
            rightInterval=rightInterval+stepSize;
            printf("%d\n",rightInterval);
            if(rightInterval>=sequenceLen)
            {
                rightInterval=sequenceLen;
                break;
            }
        }
    }
    //printf("11111111111The rightInterval is : %d\n",rightInterval);
    //printf("%d\n",sizeof(rightInterval));
    return rightInterval;
}


/********************************************************************************/
/*  Function : getRightInterval
/*  Description : 左闭右开，获取满足bwt评分的右区间位置
/*  Calls :   无

*/
/*  Called By       :
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   par1:序列； par2:左区间

*/
/*  Output     :　　　　右区间

*/
/*  Return     :　　　　右区间
/*  others     :
*/
/********************************************************************************/
int crossN(char* sequence,int leftInterval)
{
    int rightInterval=leftInterval;
    while(1)
    {
        if(sequence[rightInterval]!='N')
            break;
        rightInterval++;

    }

    return rightInterval;
}
