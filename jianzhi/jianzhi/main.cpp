#include <iostream>
#include "mianshiti.h"
using namespace std;





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
    main7_();
}
