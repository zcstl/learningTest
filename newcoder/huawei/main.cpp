#include <iostream>
#include <string>
#include <set>

using namespace std;

int main1(){
        int ain;
        int N;
        set<int> res;
        while(cin>>N){
            for(int i(0); i<N; ++i)cin>>ain, res.insert(ain);
            for(auto tmp:res)cout<<tmp<<endl;
        }
}
