/**
    输入一个字符串，可以去掉某些字符，求最大回文字符串长度
    1.当时问题：完全没思路
    1.2.后来发现可以转化为与逆序列的最长公共子序列问题，但木脑袋没做过LCS，当时也想不出来

    2.经典DP案例LCS，要点是从最后一对字符分析开始，相同和不相同情况下入手
**/
#include <iostream>
#include <string>
using namespace std;

int getLCS(char*, int, char*, int);

int main(){
    string a;
    cin>>a;
    string b(' ',a.size());
    for(int i(0), siz(a.size()); i<siz; ++i)
        b[siz-1-i]=a[i];
    //const_cast<char*>(a.c_str())
    cout<<getLCS(const_cast<char*>(a.c_str()), a.size(), const_cast<char*>(b.c_str()), b.size())<<endl;
}

int getLCS(char* a, int al, char* b, int bl){
    if(al==0 || bl==0)
        return 0;
    if(a[al]==b[bl])
        return getLCS(a, al-1, b, bl-1)+1;
    else
        return max(getLCS(a, al, b, bl-1), getLCS(a, al-1, b, bl));
}


/**
    打印蛇形矩阵
    1.当时问题： 首先题意没看明白，智商堪忧，
    对一次排开硬是理解成依次排开，往找每行数的规律方面想了
    2.要点： 分解问题成多个一圈，，，，
**/
/*
#include <iostream>
#include <string>
using namespace std;

void getSX(int**,int);
void inputValue(int**,int, int, int*);
int main(){
    int n(0);
    cin>>n;
    //
    int** arr=new int* [n];
    for(int i(0);i<n;++i)
        arr[i]=new int[n];

    getSX(arr, n);

    for(int i(0);i<n;++i)
        for(int j(0);j<n;++j)
            cout<<arr[i][j]<<" ";
    cout<<endl;
}


void getSX(int** arr, int n){
    int sta(0);
    int* val=new int;
    *val=1;
    //cout<<*val++<<endl;
    while(sta*2<n)
        inputValue(arr,sta,n,val), ++sta;
}

void inputValue(int** arr, int sta, int n, int* val){
    for(int row(sta), col(sta); col<=n-sta-1; ++col)
        arr[row][col]=(*val)++;
    for(int row(sta+1), col(n-sta-1); row<=n-sta-1; ++row)
        arr[row][col]=(*val)++;
    for(int row(n-sta-1), col(n-sta-1-1); col>=sta; --col)
        arr[row][col]=(*val)++;
    for(int row(n-sta-1-1), col(sta); row>=sta+1; --row)
        arr[row][col]=(*val)++;
}
*/


/**
    格雷码

**/


/**
    一组数中,有个数字重复一半以上,求该数
**/

/**
    大数相乘
    模仿两个数相乘的规则，被乘数为两个数中较大者
**/
/*
#include <iostream>
#include <string>
using namespace std;

void twoNumAdd(string& a, string& b);

int main(){
    //
    string a, b;
    cin>>a>>b;
    //
    unsigned char aSize=a.size(), bSize=b.size();
    for(int i(0); i<aSize; ++i)
        if(a[i]<'0' && a[i]>'9'){
            cout<<"Bad input!"<<endl;
            return -1;
        }
    for(int i(0); i<bSize; ++i)
        if(b[i]<'0' && b[i]>'9'){
            cout<<"Bad input!"<<endl;
            return -1;
        }
    //
    int maxLen(0), strLen(0), mutiTimes(0);
    if(aSize>bSize)
        maxLen=aSize, strLen=aSize*2, mutiTimes=bSize;
    else
        maxLen=bSize, strLen=bSize*2, mutiTimes=aSize, a.swap(b);

    //a*b
    string tmp(strLen, '0'), res(strLen, '0'), tmpTmp=tmp;
    for(int i(mutiTimes-1); i>=0; --i){
        int pushNum(0), s1(0), s2(0), xj(0);
        for(int j(maxLen-1); j>=0; --j){
            s1=a[j]-'0', s2=b[i]-'0', xj=s1*s2;
            //cout<<maxLen+j+(i-mutiTimes+1)<<endl;
            //cout<<(tmp[maxLen+j+(i-mutiTimes+1)]=(xj+pushNum)%10+'0')<<endl;
            tmp[maxLen+j+(i-mutiTimes+1)]=(xj+pushNum)%10+'0';
            pushNum=(xj+pushNum)/10;
        }
        tmp[maxLen-1-(mutiTimes-1-i)]=pushNum+'0';
        //cout<<tmp<<endl;
        twoNumAdd(res, tmp);
        tmp=tmpTmp;
    }
    cout<<res.substr(res.rfind('0')+1)<<endl;
}

void twoNumAdd(string& a, string& b){
    int pushNum(0), s1(0), s2(0), xj(0);
    for(int i(a.size()-1); i>=0; --i){
        s1=a[i]-'0', s2=b[i]-'0', xj=s1+s2;
        a[i]=(xj+pushNum)%10+'0';
        pushNum=(xj+pushNum)/10;
    }
}
*/

