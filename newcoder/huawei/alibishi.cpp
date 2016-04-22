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

    编程细节：由于要传递的参数比较多，所以使用引用代替参数值传递，但要注意：
    0.这种细节的优化应该是后续的优化，面试或笔试时不要在意这些，否则短时间内考虑不全的话容易出错
    常量与引用/指针会有顶层或底层常量的区别
    1.**数组退化为常量指针，所以得是常量引用；
    临时量作为实参的引用
    2.**临时量需要常量引用，int i=1;++(i+1);会出错，因为++操作数为左值，临时量逻辑上为右值，
    但肯定有物理存储，编译器做的事不用管，但它是常量或者其引用得常量引用，不求甚解！
    包裹函数
    3.递归的时候，有些条件判断，其实只要第一次判断就足够了，这个时候可以写个包裹函数专用于这种条件判断，
    然后再调用递归程序。
**/
/*
#include <stdio.h>
#define sugar(x) outputSugarForOne(randArr, sugarNum, x, len)
//**
void outputSugarForOne(int* const &randArr, int* const &sugarNum, const int &x, const int &len){
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

int getMaxOneIndex(int* const &randArr, const int& low, const int& high){
    int res=low;
    for(int i(low+1); i<=high; ++i)
        if(randArr[i]>randArr[res])
            res=i;
    return res;
}

int getSugatNum(int* const &sugarNum, const int &len){
    if(sugarNum==nullptr)
        return -1;
    int res(0);
    for(int i(0); i<len; ++i){
        printf("%d ", sugarNum[i]);
        res+=sugarNum[i];
    }
    printf("\n");
    return res;
}
//**
void outputTang_(int * const &randArr, int* const &sugarNum, const int& low, const int& high, const int& len){
    if(low>high)
        return;
    if(low==high){
        sugar(low);
        return;
    }
    int mid=getMaxOneIndex(randArr, low, high);
    outputTang_(randArr, sugarNum, low, mid-1, len);
    outputTang_(randArr, sugarNum, mid+1, high, len);
    sugar(mid);
}
void outputTang(int * const &randArr, int* const &sugarNum, const int& low, const int& high, const int& len){
    if(randArr==nullptr || sugarNum==nullptr || low>high || len!=high-low+1)
        return;//
    outputTang_(randArr, sugarNum, low, high, len);
}
//功能
void test1(){
    int randArr[9]={1,3,2,6,9,6,3,4,2};
    int sugarNum[9]={0};
    outputTang(randArr,sugarNum,0,8,9);
    printf("%d\n",getSugatNum(sugarNum, 9));

}
//负面
void test2(){
    int randArr1[3]={1,3,2};
    int* sugarNum1=nullptr;
    outputTang(randArr1,sugarNum1,0,2,3);
    printf("%d\n",getSugatNum(sugarNum1, 3));
}
//边界
void test3(){
    int randArr1[3]={1};
    int sugarNum1[1]={0};
    outputTang(randArr1,sugarNum1,0,0,1);
    printf("%d\n",getSugatNum(sugarNum1, 1));
}

int main(){
    int i=1;
    test1();
    test2();
    test3();
}

/*
void f(int* const &a){
}

int main(){
    int* b=nullptr;
    f(b);
    int c[]={1,2,3};
    f(c);
}*/

/**
    迷宫问题
    迷宫又二位数组表示,1表示墙,0表示道路,2表示礼物,给定初始位置(x,y)
    问走n步最多可以获得多少个礼物
    同时编写测试用例

    思路：
    1.类似树的深度优先遍历，也即暴力破解，忘四个方向分别递归调用，比较得最大值
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


