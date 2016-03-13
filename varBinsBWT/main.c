/*

	argv[1] is the  string to run bwt


*/


#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#include"bwtZCS.h"
#include"genoZCS.h"
#include"varBinsZCS.h"
void testBWT();

int main()
{
    //main2("chr21.fa","chr21VarBins.txt");

    //得到染色体的varbins
    //main3("chr21.fa",50000,"bwtBins.txt");

    //求navin的每个bins的bwt评分
    main4();
}

int main4()
{
    char* thisSequence=getSequenceByFileName_M("chr21.fa");
    //nt point=bwtScorePlus(thisSequence,9561193,14432540);
    int point=bwtScorePart(thisSequence,1,2);
    printf("%d\n",point);
    int size=0;
    int* sizePtr=&size;
    int* bins=getBins_M("chr21VarBins.txt",sizePtr);
    printf("%d\n",size);

    int binsNum=size-1;
    printf("The number of bins used is %d. \n",binsNum);
    int* bwtArr=(int*)malloc((binsNum)*sizeof(int));
    int* binsLenArr=(int*)malloc((binsNum)*sizeof(int));
    int i=0;
    for(;i<size-1;i++)
    {
        bwtArr[i]=bwtScorePart(thisSequence,bins[i],bins[i+1]);
        binsLenArr[i]=bins[i+1]-bins[i];
        printf("%d:%d--%d>>This bwt is %d...\n",i,bins[i],bins[i+1],bwtArr[i]);
        //printf("%d\n",bins[i]);
    }

    //write file
    outputVector(binsLenArr,binsNum,"chr21VarbinsLen.txt");
    outputVector(bwtArr,binsNum,"chr21VarbinsBwt.txt");
    free(bins);
    free(thisSequence);
}




int main3(char* chrFileName,int bwtDestScore,char* outputBinsName)
{

    getVarBins(chrFileName,bwtDestScore,outputBinsName);

}



//参数一：　该工程下chr文件名；　参数二：　该工程下bins文件名
int main2(char* chrFileName,char* binsFileName)
{
    //binsFileName放入内存并获取bins个数
    FILE* fp;
    char file[1024];
    memset(file,0x00,sizeof(file));
    strcat(file,"/home/zcs/software/NB/varBinsBWT/");
    strcat(file,binsFileName);
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
        //get into memory
    int bins[binsLen];
    printf("%s\n","aa");
    int pp=0;
    while(!feof(fp))
    {
      fscanf(fp,"%d",&bins[pp]);
      printf("%d :  %d\n",pp,bins[pp]);
      pp++;
    }
    printf("%s\n","bb");

    //chrFileName根据bins获得bwt评分
    char* gene;
    gene=getSequenceByFileName_M("chr21.fa");

    int point;
    char* thisSequence;
    int m=0,n=0;

    for (m=0;m<binsNum;m++)
    {
        thisSequence=getBinsSequence_M(gene,bins[m],bins[m+1]);
        point=bwtScore(thisSequence);
        printf("%d\n",point);
    }
    fclose(fp);
}


int main1()
{
    //测试用
    /*******************/
    //testBWT();

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
    //获取文件长度,对于基因序列
    fseek(fp,0,SEEK_END);
    int file_length=ftell(fp);
    printf("this file length is %d\n",file_length);
    fseek(fp,0,SEEK_SET);

    //
    char* test=(char*)malloc((file_length+1)*sizeof(char));
    memset(test,0x00,sizeof(test));
    //read fiel
    /*
    char tmp[51];
    memset(tmp,0x00,sizeof(tmp));
    printf("%s\n","ffff");
    int pp=0;
    while(!feof(fp))
    {
      fscanf(fp,"%s",tmp);
      strcat(test,tmp);
      memset(tmp,0x00,sizeof(tmp));
      printf("%d\n",pp);
      pp++;
    }
    printf("%s\n","ffff");
    */
    fread(test,1000000,90,fp);

    test=cutLineBreaks_M(test);
    //printf("%s\n",test);

    //
}

void testBWT(){
    char test[2001]="CAGATAAACATACCCAAAAGAAAACCCTCACCGTCAGGCGGCGAGGGTTTAACTCACATGATGATACTGACTGTTGCTCACTCTTTGAAGTGATTTGCGTCACATTCAGGGAATTCCTCAATGCAGCGCATTATGTATAAATCTTAATCGCCTTGGTTTATGGAAGACGAATTAGCGTGTTTTGTAAATCAGATGATTAATAACCCGCTTTATCAATCACAAAGGTTTTGCCACAGTTACCTGGGTGAGGTTGTGGCAAGAATGAGTTTGCAGAAAGCGGAGCGTTGATGGCGTCAGCTTTGATCGAGATCTGAATTTCAGTCAAATACGCAGGGTTACCCTGGCACGTTAGCTTAACTGCTTTCACGTTCTCTTTTCCCCAGCTTTTGGCAAAGGCGGCGTCAAAGTCACGGCGGCTCACTGTTTTACCGTAATTATCCGCAAGGAATTTTCCGGCTTCGCTCTCTTTAATTTCTTGATTCAGGCGTACCATCGTACCGAAGTATGCGTCCGGATCAAAACCAAAGCAGGCACCGTGTTTGGCATATTCGTAGCGTTCCAGGCAGGAACGTCCGCCAGCTCCTGGCATGACTTCACTTAGTTTAGCGGCCGTTTCCAGTGATAATCCGGTTTCCGGCGATGAACACATTCGGCTGGCGCGCGCTTCTGGTAGATTCGGGATTGGGCGAGTAGCGCAACCGAAGCGCATCCAGCGGCGTTCATCAACACCACGGGCAGCAACCGATTTAGGCAATCCTGGCCACAGACCATGTACGGTCAGAAAATCAGCTTTGTTGGTCGTTTCGGTTTGCAGGCGACATTCATCTCGTTCGTTACGATTTCGATCGTGTTGACTCTGGCAAAATCCGGTTTGCCAGGAGAGGGCCAGGACATAGCGATCAAAATCGCCATACTGTTTTGCCTGCAACGCTAAGGCGTTGGCAGAAGAGAAGGGAAGCAGAGAAACCGCGAGCAACGCGGCGTTACGCCAGAATGCTTTCATAATGGGTGTGGAACTCATACATACACTGAATACTATCTATTAAATCATAAAAAAGCCCGCCAGGTGGGCTTACCTGGCGGGCGTGATGATTTATTCAGCGTTTGGCGAACGTATTAGTTCCACATGGCGAGAATCGGCCAGCCAACCAACAGCAACATAGAGATGTAAATCACCCCGAAGATTGCGCCAAGACGCCAGTAATCTTTTGATTTCACATAGCCACAGCCGTAAATAATCACCCCAGGACCGGTTGCATACGGCGTCAGACAGCCCATGATACCGATAGACAGCACCAGCAGGATACACAGTTGTTCCATTGGTACGCCCGGAATACCTTTACCGACGGCCAGAATAACCGGCAGCATGGTTGCGGTGTGCGCAGACAGGCTGGCAAACAGGTAGTGTGCAAAGTAGAACACCAGAACCAGTACAATCACCGTTGCGTTTGGTGAGAATCCTTCCAGGTGCGTACTCATGGTACCGGCGAACCAGTCAATAAAACCAGAACGAGTCAGGCCGTTAGCCATCACAACCAGAGTTGCCAGGTTGACCAGTGTGTTCCATGCGCTGTTATAGCGGGTAATGTCTTTCCAAGGCACAACGTGCAGGGCCAGCATTAGCGAAACTGCCAGCAGACCAACCGCAGTAGCATTAATGACTTCACTGCCAAATACCCACAAACCTAAGCTGAGCAATACAAGGCCAATCAGTGTCCACTCTCTGCGTGTCAGCGCACCCATGGTTTTCAGTTCATCACCCGCCCAGGTTGCCACTTCTTCACTGTGTGTGATTTCCGGTTTGTACAGCACGTAGGAAAGCCACGGCGCAATGATAAGCAAGATAACCCCAACCGGCAGGAAGCAGAGGAACCACTGCAACCAGCTAATCTGGATACCGGCAATTTTGCTGACGAACTCCAGACCCAGCACGTTTGGTGCCGCACCGGTGACAAACATGGACGAACTCAGACTGGTACTAATGACCATCATCCACATCA";
    int point=0;
    point=bwtScore(test);
    printf("%d\n",point);
}
