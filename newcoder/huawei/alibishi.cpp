/**
    分糖问题
    N个孩子,随机分到一个随机数,现在分糖给他们,数字大的孩子比相邻数字小的孩子
    得到的糖要多,至少要多个糖
    同时编写测试用例

    思路：
    1.暴力解决：初始化sugar数组为0，每次遍历child数组（糖=0的部分）得到最小随机数的child，
    查看两边，给他个最小值。由于每次遍历整个数组，t复杂度为O(n*n)

    2.**类似于大根堆的中序遍历，找到最大值，然后分为左右两子树，然后递归，递归终止条件为
    low=high，此时分配low对应child的糖果，递归程序末尾再计算该次递归最大值对应的child的
    糖果，t复杂度为O(nlogn).   这种程序流的好处是先把最小数字的child分配糖果，，这句是废话
**/
#include <stdio.h>
#define sugar(x) outputSugarForOne(randArr, sugarNum, x, len)

void outputSugarForOne(int * randArr, int* sugarNum, int x, int len){
    //
    if(len==1){sugarNum[0]=1;return;}
    if(x==0){
        if(randArr[x]>randArr[x+1])
            randArr[x]=++sugarNum[x+1];
        else
            sugarNum[x]=1;
        return;
    }
    //
    if(x== len-1){
        if(randArr[x]>randArr[x-1])
            randArr[x]=++sugarNum[x-1];
        else
            sugarNum[x]=1;
        return;
    }

    int right=randArr[x+1], rightSugar=sugarNum[x+1], left=randArr[x-1], leftSugar=sugarNum[x-1];
    if(randArr[x]<left && randArr[x]<right){
        sugarNum[x]=1;
        return;
    }
    if(randArr[x]>left && randArr[x]>right){
        sugarNum[x]=leftSugar>rightSugar?leftSugar:rightSugar+1;
        return;
    }
    if(randArr[x]>left)
        sugarNum[x]=++leftSugar;
    if(randArr[x]>right)
        sugarNum[x]=++rightSugar;
}

int getMaxOneIndex(int* randArr, int low, int high){
    int res=low;
    for(int i(low+1); i<=high; ++i)
        if(randArr[i]>randArr[res])
            res=i;
    return res;
}

int getSugatNum(int* sugarNum, int len){
    if(sugarNum==nullptr)
        return -1;
    int res(0);
    for(int i(0); i<len; ++i){
        res+=sugarNum[i];
    }
    return res;
}

void outputTang(int * randArr, int* sugarNum, int low, int high, int len){
    if(randArr==nullptr || sugarNum==nullptr || low>high)
        return;
    if(low==high){
        sugar(low);
        return;
    }
    int mid=getMaxOneIndex(randArr, low, high);
    outputTang(randArr, sugarNum, low, mid-1, len);
    outputTang(randArr, sugarNum, mid+1, high, len);
    sugar(mid);
}



int main(){
    int randArr[9]={1,3,2,6,9,6,3,4,2};
    int sugarNum[9]={0};
    outputTang(randArr,sugarNum,0,8,9);
    printf("%d\n",getSugatNum(sugarNum, 9));


    int randArr1[3]={1,3,2};
    int* sugarNum1=nullptr;
    outputTang(randArr1,sugarNum1,0,2,3);
    printf("%d\n",getSugatNum(sugarNum1, 3));
}

/**
    迷宫问题
    迷宫又二位数组表示,1表示墙,0表示道路,2表示礼物,给定初始位置(x,y)
    问走n步最多可以获得多少个礼物
    同时编写测试用例
**/
#include <stdio.h>
#define getAroad(x,y) getSweat(amap, xlen, ylen, x, y, n)

/*
int maxOne(int a, int b, int c, int d){
    int x=a>b?a:b;
    int y=c>d?c:d;
    return x>y?x:y;
}
int getSweat(int** amap, int xlen, int ylen, int x, int y, int n){
    if(x>xlen-1 || x<0 || y>ylen-1 || y<0 || n==0)
        return 0;
    int res(0);
    if(amap[x][y]==1)
        return 0;
    --n;
    if(amap[x][y]==2)
        res+=1;
    int a1=getAroad(x-1, y);
    int a2=getAroad(x+1, y);
    int a3=getAroad(x, y-1);
    int a4=getAroad(x, y+1);
    return res+maxOne(a1, a2, a3, a4);
}
int testSweatNumByXY(int** amap, int xlen, int ylen, int x, int y, int n){
    if(amap==nullptr || *amap==nullptr || xlen<1 || ylen<1){
        printf("Bad input!!!!Please check the input!!\n");
        return 0;
    }
    return getSweat(amap, xlen, ylen, x, y, n);

}


void test1(){
    int a[3]={1,1,1}, b[3]={0,2,2},c[3]={1,1,1};
    int* test[3]={a,b,c};
    printf("%d\n",testSweatNumByXY(test,3,3,1,0,2));
}
void test2(){
    int a[3]={1,1,1}, b[3]={0,2,2},c[3]={1,1,1};
    int* test[3]={a,b,c};
    printf("%d\n",testSweatNumByXY(test,3,3,0,0,2));
}
void test3(){
    int a[3]={1,1,1}, b[3]={0,2,2},c[3]={1,1,1};
    int* test[3]={};
    printf("%d\n",testSweatNumByXY(test,3,3,1,0,2));
}
int main(){
    test1();
    test2();
    test3();
}
*/


