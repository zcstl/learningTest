
/**
    1.除了变量/对象定义和break，continue等关键词外，函数调用是表达式，单个字面值常量是表达式，
    数组名[1]也是表达式，表达式可以使用.运算符，作为style，使code行数合理减少，结合包裹函数，效果更好～～
    2.即使函数形参类型是数组，形参使用时也会退化为指针；
    2.1.数组名在表达式里退化为指针，=作为运算符函数，也是表达式，故实参形参的值拷贝中，数组会退化，
    因为这种退化，int i[]={1,2,3};i[55],i[11]=1;是合法，故数组作为实参时，多加上大小。
    2.2.作为左值时，数组名是数组类型，不退化！
**/

//首先,不同于oj系统,这种类型的机试题,虽然输入都是合法(例如华为),但都是一个程序
//运行,输入多个测试用例,所以有以下两点要注意:
//1.外层要有个while循环,对应每次测试
//2.若把容易定义在外面,则每一次循环,记得清空容器,,
//对于此题,完全可以先用stl进行排序,若有时间再自己写个快排

/*

#include <iostream>
#include <algorithm> //swap
#include <vector>
using namespace std;

bool cmpZCS(const int& t1, const int& t2)
{
    return !(t2<t1);
}

void quickSort(int*,int,int);
int main11()
{
    //int test[]={1,2,3,4,5,6};int tt=quickSort(test,1,3);cout<<test[99]<<endl,test[1]=1,test[90]=0;return 0;
    //int test[]={3,4,1,5,6,77,1};quickSort(test,0,6);for(int t=0;t<7;++t)cout<<test[t]<<endl;return 0;
    int n(0);
    vector<int> ns;
    int one(0);
    while(cin>>n)
    {
        int _count(0);
        //若ns没有被清空,则保留上次的测试用例,则会出错,,,
        ns.clear();
        while(cin>>one)
        {
            ++_count;
            ns.push_back(one);
            if (_count==n)break;
        }
        //cmpZCS为形参元素类型的比较函数,且元素一比元素二小返回true,是升序
        sort(ns.begin(),ns.end(),cmpZCS);

        int preOne(*ns.begin());
        cout<<preOne<<endl;

        //for(auto tmp:ns)cout<<tmp<<endl;
        for(auto tmp=ns.begin();tmp<ns.end();++tmp)
        {
        	if(*tmp==preOne)continue;
            cout<<*tmp<<endl,preOne=*tmp;
  	  	}

    }
}

//要熟悉快排写法
//这种两个小标pre与low从一端开始处理，好处是这一端是稳定的，pivot选谁都一样，位置保存下来，最后与pre-1（若在左边，反之pre）交换便可
int _partition(int* n, int low, int high)
{
    int pivot=n[high];
    int pre=low;
    while(low<high)
    {
        if(n[low]>pivot)
        {
            ++low;
            continue;
        }
        swap(n[low], n[pre]), ++low, ++pre;
    }
    //swap(n[pre], pivot);
    swap(n[pre], n[high]);
    return pre;
}

//quickSort的递归要熟悉！
void quickSort(int* n, int low, int high)
{
    if (low>=high) return;
    int pivot=_partition(n, low, high);
    quickSort(n,low,pivot-1);
    quickSort(n,pivot,high);
}

*/


/*
//宏定义是预处理  #define A 10
//数字 二进制 八进制 十进制  十六进制间的转换
//十进制转二进制， 不断除2取余，直到被除数为0， 结果倒叙排列
//stack<int> res; res.push; res.top; res.pop;
//queue<int> res; res.push; res.pop; res.front;
#include <iostream>
#include <string>
#include <math.h>

//miss #
define A 10;
define B 11;
define C 12;
define D 13;
define E 14;
define F 15;

using namespace std;

int toTen(char a)
{
    if (a>='0' && a <='9')
        return a-'0';
    return a-'A'+10;
}


int main()
{
    string oin, oou;
    while(cin>> oin)
    {
        oou=oin.substr(2);
        float sum(0.0);
        //cout<<oou<<endl;
        for (int i=oou.size()-1, j(0); i>=0;++j, --i)
            //cout<<toTen(oou[i]);
            sum=sum+(toTen(oou[i])/1.0)*pow(16/1.0,j/1.0);
        cout<<sum<<endl;


    }

}
*/

/*
//十六进制转八进制
//可先转换为十进制，虽然比较多余，但不失为一个可以快速写出来的方法
#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int toTen(char a)
{
    if (a>='0' && a <='9')
        return a-'0';
    return a-'A'+10;
}

int slToTen(string s)
{
    string si=s.substr(2);
    float sum(0.0);
    for(int i=si.size()-1, j=0; i>=0;--i, ++j)
        sum+=(toTen(si[i])/1.0)*pow(16.0,j/1.0);
    return sum;
}

int main()
{
    string inp;
    int ten;
    stack <int> outSix;
    while(cin>>inp)
    {
        ten=slToTen(inp);
        if(ten==0)
        {
            cout<<0<<ten<<endl;
            continue;
        }
        while(ten)
        {
            outSix.push(ten%8);
            ten/=8;
        }
        cout<<0;
        while(!outSix.empty())
        {
            cout<<outSix.top();
            outSix.pop();
        }
        cout<<endl;
    }

}
*/


//有些冗余的代码已被注释
/*
#include <iostream>

using namespace std;

int main()
{
    int N(0);
    while(cin>>N)
    {
        if (N==0)
            return 0;
        if (N<1 || N>100);//

        //if(N%2 == 1)
        //   --N;
        cout<<N/2<<endl;

    }


}
*/
