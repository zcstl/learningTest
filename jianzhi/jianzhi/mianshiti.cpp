#include "mianshiti.h"
#include <array>
#include <vector>
/**
hash:以空间换时间
**/
char jzOffer::ti35::findFirstChar(string str){
    if(str.size()==0) return NULL;
    int arr[256]={0};
    for (int i(0); i<str.size(); ++i)arr[(int)str[i]]+=1;
    char res;
    for (int i(0); i<str.size();++i)
        if(arr[(int)str[i]]==1){
            res=str[i];
            break;
        }
    return res;
}


/**
array与数组相比,作为类模板,提供了成员函数操作高效,但大小也是编译时确定
**/
void wdBaoDian::ti257::findSmallK(){
    int nums(0), k(0);
    while(cin>>nums>>k){
        if(nums<=0);//
        if(k<=0);//
        if(k>=nums);//
        vector<int> res;
        int aNum(0);
        for(int i=0;i<k;++i)cin>>aNum, res.push_back(aNum);
        vector<int>::iterator sm;
        //nums limited,,
        while(cin>>aNum){
            sm=findMax(res);
            if(aNum<*sm)swap(*sm,aNum);
        }
        for(auto tmp:res)cout<<tmp<<endl;
    }
}

//vector<int>::iterator wdBaoDian::ti257::findMax(const vector<int>& nums){
//const引用使得返回的迭代器类型也是const,便不能拷贝给非const的迭代器,报类型mismatch
//如果是const引用,便只能调用cbegin();调用begin的话报的错是没有相关的=运算符重载,????内在实现不明?
vector<int>::iterator wdBaoDian::ti257::findMax(vector<int>& nums){
    vector<int>::iterator res=nums.begin();
    for(auto tmp=nums.begin(); tmp<nums.end(); ++tmp)if(*tmp>*res)res=tmp;
    return res;
}
