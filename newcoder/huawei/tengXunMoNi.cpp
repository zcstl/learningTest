/**
    0-1背包问题
    DP，递推填表

    val[]表示物品价值，wgt[]表示物品重量，重量为0的物品价值为0
    arr[i][j]表示背包重量为i且只能选1到j个物品时的最价值

    1.若是部分背包问题，即物品按计量单位算，则贪心解决
    2.若问法是必须装满背包的前提下，则0-1背包问题的初始化为负无穷
**/
/*
#include <iostream>
#include <string>
using namespace std;

#define nums 3
#define totalWeigth 5

int main(){
    //加上0  编程更方便
    int val[nums+1]={0, 60, 100, 120};
    int wgt[nums+1]={0, 1, 2, 3};
    int arr[totalWeigth+1][nums+1]={0};

    for(int i(1); i<=totalWeigth; ++i)
        for(int j(1); j<=nums; ++j)
            if(wgt[j]>i)
                arr[i][j]=arr[i][j-1];
            else
                arr[i][j]=max(arr[i][j-1], arr[i-wgt[j]][j-1]+val[j]);
    cout<<arr[totalWeigth][nums]<<endl;
}
*/

/**
    bitset的使用
**/


/**
    编程之美2.1: 判断unsigned char变量二进制表示中1的个数
    思路:
    1.比较low的思路:循环吗模2取余并除2, 计算余数为1的个数
    2.判断低位是否为1(& 0x1)然后右移1位(>>1),循环更新num直到为0停止
    3.查表法,统计256个数字的1的个数建表,典型的空间换时间,,,

    >>运算符的操作数是右值,~运算符的操作数也是右值
**/
/*
#include <iostream>
#include <string>
using namespace std;

int countOne(unsigned char a);

int main(){
    unsigned char a(8);
    cout<<countOne(a)<<endl;
}
int countOne(unsigned char a){
    int num(0);
    //while(a>=1)
    while(a){
        num+=a&0x1;
        a>>=1;
    }
    return num;
}
*/

/**
    输入一个字符串，可以去掉某些字符，求最大回文字符串长度
    1.当时问题：完全没思路
    1.2.后来发现可以转化为与逆序列的最长公共子序列问题，但木脑袋没做过LCS，当时也想不出来

    2.经典DP案例LCS，要点是从最后一对字符分析开始，相同和不相同情况下入手
**/
/*
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
*/

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

