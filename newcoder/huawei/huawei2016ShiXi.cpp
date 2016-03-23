/**
    此题为求二叉树某节点深度问题，做题时题意理解错误
    简要的实现： 构造一颗二叉树便可以了
**/
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findDepth(vector<string>& res, char a){
    for(int i(0), sizet=res.size(); i<sizet; ++i)
        if(res[i][0]==a)return res[i][1]-'0';
    return -1;
}
int main(){
    string ain, aserch;
    vector<string> res;
    unsigned int de(0);
    while(cin>>ain){
        if(ain.empty())continue;
        for(int i(0), sizet=ain.size(); i<sizet; i+=2)
            res.push_back(ain.substr(i,2));
        de=(*--res.end())[1]-'0';
        //cout<<de<<endl;cout<<(*--res.end())[1]<<endl;
        cin>>aserch;
        for(int i(0),sizet=aserch.size(); i<sizet; ++i){
            if (aserch[i]==-1){
                cout<<0<<" ";
                continue;
            }
            cout<<de-findDepth(res, aserch[i])+1<<" ";
        }

        cout<<endl;
        res.clear();
        ain.clear();
        aserch.clear();
    }
}
*/


 /**题目easy的话，代码质量很重要！
    1.此题为对输入的数字进行去重排序输出
    做题时的问题： 首先是编译环境没有用vs2013导致一些编译错误发生，
    如没有包含string，其次，对oj系统的不了解，没有看到运行错误是因
    输出格式（元素之间应该有空格，最后一个元素末尾没有空格）,并且该
    代码没有对N的合法性进行检测，且没有输出换行，，，，，
    2.另外，快排也写错了，，原因在于对stl vector的不熟悉
    3.此题最好的方法使用set；
    4.用vector的话会因为大小改变而变得慢，new个数组，在用sort对数组
    排序（两个参数分别是首尾指针或地址）

 **/
 /*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int aPartition(vector<int>& nums, int low, int high){
    //int pivot=*nums.begin();//
    int pivot=nums[low];
    while(low<high){
        while(low<high && nums[high]>=pivot)--high;
        //*(nums.begin()+low)=*(nums.begin()+high);
        nums[low]=nums[high];
        while(low<high && nums[low]<=pivot)++low;
        nums[high]=nums[low];
    }
    nums[low]=pivot;
    return low;
}

void sortZCS(vector<int>& nums, int low, int high){
    if(low<high){
        int pivot=aPartition(nums, low, high);
        sortZCS(nums, low, pivot-1);
        sortZCS(nums, pivot+1, high);
    }
}

int main(){
    vector<int> nums;
    unsigned int N;
    int tmp(0);
    int pre(0);
    while(cin>>N){
        for(int i(0); i<N; ++i)cin>>tmp, nums.push_back(tmp);
        sortZCS(nums, 0, nums.size()-1);
        pre=*nums.begin();
        cout<<pre;
        for(int i(0); i<N; ++i){
            if(nums[i]==pre)continue;
            cout<<nums[i];
            pre=nums[i];
        }
        nums.clear();
    }
}
*/

/**
    输出输入字符串中的大写部分
**/
/*
#include <iostream>
using namespace std;
int main(){
    string str;
    while(cin>>str){
        for(int i(0), sizet(str.size()); i<sizet; ++i)
            if(str[i]>='A' && str[i]<= 'Z')cout<<str[i]<<endl;
        str.clear();
    }
}

*/
