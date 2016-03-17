
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

typedef pair<string, int> PAIR;
bool cmpByValue(const PAIR& p1, const PAIR& p2);

int main()
{
    string oneInput;
    int rowN;
    map<string, int> res;
    while(cin>>oneInput)
    {
        cin>>rowN;
        ++res[oneInput+" "+rowN];
    }
    vector<PAIR> resTmp(res.begin(),res.end());
    sort(resTmp.begin(),resTmp.end(),comByValue);
    char* f1(nullptr);
    char* f2(nullptr);
    for(auto i=resTmp.begin();i<resTmp.end();++i)
    {
        p1=strtok(&(i->first)," ");
        p2=strtok(NULL," ");
        cout<<p1<<" "<<p2<<" "<<i->second<<endl;
    }

}

bool cmpByValue(const PAIR& p1, const PAIR& p2)
{
    return p1.second<p2.second;
}
