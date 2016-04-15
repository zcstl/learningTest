#include "mianshiti.h"
#include <array>
#include <vector>

/**
    输入一个整数,输出该整数二进制表示中1的个数
    注:负数补码表示,不是原码表示

    原码->补码:取反加1,符号位不变
    补码->原码:取反加1,符号位不变
    取反操作符:~, 符号位也会改变

    考虑到负数的情况:1.与a=1进行与操作,然后与左移一位的a进行与操作,,,
    2.(n-1)&n,则最右边的1会成为0
**/
/*输入负数则计算出错
int jzOffer::ti10::numberOfOne(int n){
    int times(0);
    //if(n<0)n=-n, ++times;  原码表示时
    //if(n<0)n=~n+1;
    while(n>0){
        times+=n&1;
        n=n>>1;
    }
    return times;
}
*/

int jzOffer::ti10::numberOfOne(int n){
    int times(0);
    while(n)n=(n-1)&n, ++times;
    return times;
}

/**
    有序一次旋转数组的最小值
    *******
    核心是重复元素的考虑,若输入没有重复元素,则只需@1便可以,若有则需要增加@2
    思路:把所有可能的下标更新情况都考虑,即使有重复元素, 也就多了个分类,多考虑一种情况而已
**/
#define ZCSError() {cout<<"nullptr!!"<<endl;return-1;}
int jzOffer::ti8::minZ(int* a, int l, int h){
    if(a==nullptr)ZCSError();
    if(l==h)return a[l];
    if(l>h){
        cout<<"error: low is higher than high!"<<endl;
        return -1;
    }

    int mid((l+h)/2);
    int mid1((l+h)/2), l1(l), h1(h);
    //@1
    while(mid>l){
        if(a[mid]>=a[l] && a[mid]>a[h])
            l=mid;
        else
            h=mid;
        mid=(l+h)/2;
    }
    //@2
    while(mid1>l1){
        if(a[mid1]>=a[l1] && a[mid1]>=a[h1])
            l1=mid1;
        else
            h1=mid1;
        mid1=(l1+h1)/2;
    }
    int m1=a[l]<a[h]?a[l]:a[h];
    int m2=a[l1]<a[h1]?a[l1]:a[h1];

    return m1<m2?m1:m2;
}


/**
    由二叉树的前序和中序遍历,重建二叉树的结构
**/

int jzOffer::ti6::isFind(int* a, int* b, int len){
    int idx(0);
    while(idx<len){
        if(a[0]==b[idx])
            return idx;
        else
            ++idx;
    }
    return -1;
}

jzOffer::ti6::bstNode* jzOffer::ti6::constructBst(int* preOrder, int* inOrder, int len){
    bstNode* node=nullptr;
    if(len==0 || preOrder==nullptr || inOrder==nullptr)
        return node;
    int idx=isFind(preOrder, inOrder, len);
    if(idx==-1){
        cout<<"Bad find!"<<endl;
        return node;
    }
    else{
        node=new(nothrow) bstNode;
        if(node==nullptr){
            cout<<"New error!"<<endl;
            return node;
        }
        node->val=preOrder[0];
        if(idx==0){
            node->pL=(bstNode*)nullptr;
            node->pR=constructBst(preOrder+1, inOrder+1, len-1);
        }
        else{
            node->pL=constructBst(preOrder+1, inOrder+0, idx);
            node->pR=constructBst(preOrder+idx+1, inOrder+idx+1, len-idx-1);
        }
        return node;
    }
}


/**
对同一行,同一列的元素都递增的二位数组进行查找
**/
void jzOffer::ti3::test(){
    int row(0), col(0), elem(0);
    cin>>row>>col>>elem;
    if(row<=0 || col<=0)return;

    int** arr=new int*[col];for(int i(0); i<col; ++i)arr[i]=new int[row];
    for(int i(0); i<row; ++i)for(int j(0); j<col; ++j)cin>>arr[i][j];


    if(find2DElement(arr, row, col, elem))
        cout<<"Find it!"<<endl;
    else
        cout<<"Don't find it!"<<endl;
}

bool jzOffer::ti3::find2DElement(int** arr, int row, int col, int n){
    for(int i(0), j(col-1); i<row && j>=0;)
        if(arr[i][j]==n)
            return true;
        else if (n>arr[i][j])
                ++i;
            else
                --j;
    return false;
}

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
