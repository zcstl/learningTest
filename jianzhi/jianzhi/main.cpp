#include <iostream>
#include "mianshiti.h"
using namespace std;

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
    main10();
}
