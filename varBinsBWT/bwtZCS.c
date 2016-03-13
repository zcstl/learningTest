
/*
    BWT变换实现

*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#include"bwtZCS.h"
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
int bwtScore(char* sequence)
{
    int file_length=0;
    file_length=strlen(sequence);
	char* head_column=(char*)malloc((file_length+1)*sizeof(char));
    memset(head_column,0x00,sizeof(head_column));
	char* tail_column=(char*)malloc((file_length+1)*sizeof(char));
    memset(tail_column,0x00,sizeof(tail_column));

	int point=0;
	int* point_pt=&point;
	circular_shift(sequence,head_column,tail_column,point_pt);
        free(head_column);
        free(tail_column);
	//printf("%d\n",point);
	return point;
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

int bwtScorePlus(char* sequence,int sta,int ed)
{
    int len=0;
    len=strlen(sequence);
    char* thisSequence=(char*)malloc((len-(ed-sta)+1)*sizeof(char));
    memset(thisSequence,0x00,sizeof(thisSequence));
    int i=0,j=0;
    for (i=0;i<len;i++)
    {
        if((i>=sta)&&(i<ed))
            continue;

        thisSequence[j]=sequence[i];
        j++;
    }

    thisSequence[j]='\0';
    int point;
    point=bwtScore(thisSequence);
        free(thisSequence);
    return point;
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

int bwtScorePart(char* sequence,int sta,int ed)
{
    int len=0;
    len=strlen(sequence);
    char* thisSequence=(char*)malloc((len-(ed-sta)+1)*sizeof(char));
    memset(thisSequence,0x00,sizeof(thisSequence));
    int i=0,j=0;
    for (i=0;i<len;i++)
    {
        if (i<sta)
            continue;
        if (i>=ed)
            break;

        thisSequence[j]=sequence[i];
        j++;
    }

    thisSequence[j]='\0';
    int point;
    point=bwtScore(thisSequence);
        free(thisSequence);
    return point;
}


/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
/*  Function : sort_by_dict
/*  Description : 将两字符串按照第一列的字典序（acgt，可自定义）排列,并大写转小写
/*  Calls :   无

*/
/*  Called By       :   circular_shift
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   两个字符型指针

*/
/*  Output     :

*/
/*  Return     :
/*  others     :
*/
/********************************************************************************/

void sort_by_dict(char* head_column,char* tail_column)
{
//  change case
    int y=0;
    capitalToLowerCase(head_column);
    capitalToLowerCase(tail_column);
    /*
    while(head_column[y]!='\0')
    {   //wait for improvement
        if((head_column[y]>=65)&&(head_column[y]<=90))
        {
            head_column[y]=head_column[y]+32;
            //tail_column[y]=tail_column[y]+32;
        }
        if((tail_column[y]>=65)&&(tail_column[y]<=90))
        {
            //head_column[y]=head_column[y]+32;
            tail_column[y]=tail_column[y]+32;
        }

        y++;
    }
    */
	int num=(int)strlen(head_column);
	int file_length=strlen(head_column);
    //char tmp_head[num+1];
    char* tmp_head=(char*)malloc((file_length+1)*sizeof(char));
    memset(tmp_head,0x00,sizeof(tmp_head));
	//char tmp_tail[num+1];
    char* tmp_tail=(char*)malloc((file_length+1)*sizeof(char));
    memset(tmp_tail,0x00,sizeof(tmp_tail));
    //n or N直接被忽略
	char dict[4]={'a','c','g','t'};

	int i,j,m=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<num;j++)
		{
			if(head_column[j]==dict[i])
			{
				tmp_head[m]=head_column[j];
				tmp_tail[m]=tail_column[j];
				head_column[j]='k';
				tail_column[j]='k';
				m++;
			}
		}

	}
	tmp_head[m]='\0';
	tmp_tail[m]='\0';
//	printf("%s\n%s\n",tmp_head,tmp_tail);
	i=0;

	while(tmp_head[i]!='\0')
	{
		head_column[i]=tmp_head[i];
		tail_column[i]=tmp_tail[i];
		i++;
	}
	head_column[i]='\0';
	tail_column[i]='\0';
        free(tmp_head);
        free(tmp_tail);
}

/********************************************************************************/
/*  Function : measure_specificity
/*  Description : 将BWT转换后的字符的复杂程度进行评估
/*  Calls :

*/
/*  Called By       :   circular_shift
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   一个字符型指针

*/
/*  Output     :

*/
/*  Return     :
/*  others     :
*/
/********************************************************************************/
int measure_specificity(char* tail_column)
{
	int i=1;
	int count=1;
	char tmp=tail_column[0];
	while(tail_column[i]!='\0')
	{
		if(tail_column[i]!=tmp)
		{
			count++;
			tmp=tail_column[i];
		}
		i++;
	}
	return count;
}

/********************************************************************************/
/*  Function : circular_shift
/*  Description : 将字符串BWT变换，输出第一列和最后一列，并对其进行评分
/*  Calls :   measure_specificity ， sort_by_dict

*/
/*  Called By       :   main
/*  Global Variable :
/*  Table Accessed  :
/*  Table Updated   :
/*  Input      :   三个字符型指针，一个整形指针

*/
/*  Output     :

*/
/*  Return     :
/*  others     :
*/
/********************************************************************************/

void circular_shift(char* str,char* head_column,char* tail_column,int* point)
{
	int num=strlen(str);
	int i;
	for(i=0;i<num;i++)
	{
		head_column[i]=str[i];
		tail_column[i]=str[(num-1+i)%(num)];

	}

	head_column[i]='\0';
	tail_column[i]='\0';
	//printf("%s\n%s\n",head_column,tail_column);

	sort_by_dict(head_column,tail_column);
	*point=measure_specificity(tail_column);
}

