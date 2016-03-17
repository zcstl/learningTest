/*
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
    //char tmp[1024];
    int rowN;
    map<string, int> res;
    while(cin>>oneInput)
    {
        cin>>rowN;
        ++res[oneInput+" "+to_string(rowN)];
    }
    vector<PAIR> resTmp(res.begin(),res.end());
    sort(resTmp.begin(),resTmp.end(),cmpByValue);
    char* f1(nullptr);
    char* f2(nullptr);
    for(auto i=resTmp.begin();i<resTmp.end();++i)
    {
        char* tmp=(char*)malloc(1024*sizeof(char));
        strcpy(tmp,i->first.c_str());
        f1=strtok(tmp," ");
        f2=strtok(NULL," ");
        cout<<f1<<" "<<f2<<" "<<i->second<<endl;
    }

}

bool cmpByValue(const PAIR& p1, const PAIR& p2)
{
    return p1.second<p2.second;
}

*/
