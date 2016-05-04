#include <iostream>
#include "mianshiti.h"
using namespace std;

int main36(){
    jzOffer::Ti36 test;
    int nums[]={7, 5, 6, 4};
    test.countInversePairs(nums, 0, 3);
    //int nums1[]={2,1};
    //test.countInversePairs(nums1, 0, 1);
}

int main33(){
    jzOffer::Ti33 test;
    int nums[]={3, 23, 123};
    test.smallestNumsArrPermutation(nums, 3);
}

int main31(){
    jzOffer::Ti31 test;
    int nums[]={1,-2,3,10,-4,7,2,-5};
    cout<<test.getMaxChildArray(nums, 8)<<endl;
}

/**
    getPivot声明放在mianshiti.h中，实现放在.cpp中，使用其会报错
**/
int getPivot(int* nums, int low, int high){
    return low;
}
int main30(){
    jzOffer::Ti30 test;
    int nums[]={1,2,7,5,6,3,4,9,10,8};
    test.getSmallestNums(nums, 10, 3, getPivot);
}

int main21(){
    jzOffer::ti21<int> test;
    test.push(2);
    test.push(3);
    test.push(1);
    test.push(0);
    //程序执行先执行test.minT再执行topAndPop
    /**注意<<的执行顺序**/
    cout<<test.topAndPop()<<" "<<test.minT()<<endl;
    cout<<test.topAndPop()<<" "<<test.minT()<<endl;
    cout<<test.topAndPop()<<" "<<test.minT()<<endl;
    cout<<test.topAndPop()<<" "<<test.minT()<<endl;
    cout<<test.topAndPop()<<" "<<test.minT()<<endl;
}

int main14(){
    int a[]={3,6,8,1,3,6,6,7,1,1};
    int e[]={1,3,5,7,9,2,4,6,8,10};
    int f[]={2,4,6,8,10,1,3,5,7,9};
    int b[1]={1};//数组没有指定大小的话，列表初始化不能为空，但此在gnu下没有报错
    int* c=nullptr;
    jzOffer::ti14 test;
    test.adjustArrayToApartOdd(a, 10);
    test.adjustArrayToApartOdd(e, 10);
    test.adjustArrayToApartOdd(f, 10);
    test.adjustArrayToApartOdd(b, 0);
    test.adjustArrayToApartOdd(c, 10);
}

int main12(){
    jzOffer::ti12 test;
    test.print1ToMaxN(5);
}

int main11(){
    jzOffer::ti11 test;
    printf("%f\n",test.power(2,8));
    printf("%f\n",test.power(2,9));
    printf("%f\n",test.power(-1,4));
    printf("%f\n",test.power(0,-1));
    printf("%f\n",test.power(2,-1));
    printf("%f\n",test.power(-2,-1));
    printf("%f\n",test.power(2,1));
}

int main10(){
    jzOffer::ti10 test;
    cout<<test.numberOfOne(10)<<endl;
    cout<<test.numberOfOne(-10)<<endl;
    cout<<test.numberOfOne(0)<<endl;
}

int main8(){
    int a[]={3,4,5,1,2};
    int b[]={1};
    int c[]={1,2,3,4,5};
    int d[]={1,0,1,1,1};
    int e[]={1,1,1,0,1};
    int f[]={0,1,1,2,2};
    int g[]={1,2,2,1,1};
    int* h(nullptr);
    int i[]={0,0,0,1,1,1,2,3,4,5,6,7,8,9,9,9};
    int j[]={7,8,9,9,9,0,0,0,1,1,1,2,3,4,5,6};
    int k[]={1,2,3,4,5,6,7,8,9,9,9,0,0,0,1,1};
    jzOffer::ti8 test;
    cout<<test.minZ(a, 0, 4)<<endl;
    cout<<test.minZ(b, 0, 0)<<endl;
    cout<<test.minZ(c, 0, 4)<<endl;
    cout<<test.minZ(d, 0, 4)<<endl;
    cout<<test.minZ(e, 0, 4)<<endl;
    cout<<test.minZ(f, 0, 4)<<endl;
    cout<<test.minZ(g, 0, 4)<<endl;
    cout<<test.minZ(h, 0, 4)<<endl;
    cout<<endl;
    cout<<test.minZ(i, 0, sizeof(i)/sizeof(int)-1)<<endl;
    cout<<test.minZ(j, 0, sizeof(j)/sizeof(int)-1)<<endl;
    cout<<test.minZ(k, 0, sizeof(k)/sizeof(int)-1)<<endl;
}

int main7_(){
    jzOffer::ti7_<int> test;
    test.push(1);
    test.push(2);
    cout<<test.topAndPop()<<endl;
    cout<<test.topAndPop()<<endl;
}

int main7(){
    jzOffer::ti7<int> test;
    test.pushTail(1);
    test.pushTail(2);
    cout<<test.popHead()<<endl;
    cout<<test.popHead()<<endl;
}


void postOrder(jzOffer::ti6::bstNode* tree){
    if(tree==nullptr)return;
    cout<<tree->val<<" ";
    postOrder(tree->pL);
    postOrder(tree->pR);
}

int main6()
{
    jzOffer::ti6 test;
    //int a[]={1,2,4,7,3,5,6,8};
    //int b[]={4,7,2,1,5,3,8,6};
    int a[]={1}, b[]={1};
    jzOffer::ti6::bstNode* tree=test.constructBst(a, b, 1);
    postOrder(tree);
    cout<<endl;
    return 0;
}

int main(){
    main36();
}
