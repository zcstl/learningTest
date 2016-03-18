#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, int> ER;
bool cmpZCS(const ER&, const ER&);

int main()
{
    string sin;
    vector<ER> res;
    while(getline(cin, sin))
    {
        //if (sin==NULL)
        if (sin.size()==0)
        {
            //
        }
        int idx=sin.rfind('\\');
        sin=sin.substr(idx+1);
        int tag(0);//()赋初始值,只能初始化时用
        for (auto tmp=res.begin(); tmp<res.end(); ++tmp)
        {
            if (tmp->first==sin)
            {
                tag=1;
                ++tmp->second;
                break;
            }
        }
        if (tag==0)
        {
            ER tmp(sin,1);
            res.push_back(tmp);
            //cout<<tmp.first<<"ffrf"<<endl;
        }
    }
    //
    stable_sort(res.begin(), res.end(), cmpZCS);
    int i(1);
    //cout<<res.size()<<endl;
    for(auto tmp=res.begin();tmp<res.end()&&i<=8;++i, ++tmp)
    {
        int idx=tmp->first.rfind(' ');
        if (idx<=16)
            cout << tmp->first<<' '<<tmp->second<<endl;
        else
        {
            tmp->first.erase(0, idx-16);
            cout << tmp->first<<' '<<tmp->second<<endl;
        }
    }
}



