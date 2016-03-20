#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmpZCS(const int t1, const int t2)
{
    return t1<t2;
}

int main()
{
    int n;
    vector<int> ns;
    int one;
    while(cin>>n)
    {
        int _count(0);
        while(cin>>one)
        {
            ++_count;
            ns.push_back(one);
            if (_count==n)break;
        }
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
