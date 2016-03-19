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


#include <iostream>
#include <string>
#include <math.h>
/*
define A 10;
define B 11;
define C 12;
define D 13;
define E 14;
define F 15;
*/
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



}



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

        if(N%2 == 1)
            --N;
        cout<<N/2<<endl;

    }


}
添加笔记

