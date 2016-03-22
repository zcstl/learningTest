/*
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(){
    int N(0);
    vector<int> nums;
    while(cin>>N){
        nums.clear();
        for(int i=0;i<N;++i)nums.push_back(i);
        auto biginIter=nums.begin();
        for(int idx=0, sizet=nums.size(); sizet>1;){
            idx=(idx+2)%nums.size();
            nums.erase(biginIter+idx);
            --sizet;
        }
        cout<<*nums.begin()<<endl;
    }


}

*/


/*
#include <iostream>
#include <vector>

using namespace std;

bool findThis(const vector<char>& a, char b){
    for(auto tmp: a)if(tmp==b)return 1;
    return 0;
}

int main(){
    string str;
    vector<char> nums;
    while(cin>>str){
        nums.clear();
        for(auto tmp : str){
            if(findThis(nums, tmp))continue;
            nums.push_back(tmp);
        }
        for(auto tmp : nums)cout<<tmp;
        cout<<endl;

    }
}

/*
int main(){
    string str;
    set<char> nums;
    while(cin>>str){
        nums.clear();
        for(auto tmp : str)nums.insert(nums.end(), tmp);
        for(auto tmp: nums)cout<<tmp;
        cout<<endl;

    }


}
*/


*/


#include <iostream>
//#include <array>

using namespace std;

int insertFirstSutable(int (&nums) [9][9], int i, int j){
    int isHave[10]={0};
    for(int m(0); m<9; ++m)++isHave[nums[i][m]];
    for(int m(0); m<9; ++m)++isHave[nums[m][j]];
    for(int m(1); m<9; ++m)if(isHave[m]==0)return m;
    return -1;
}


int main(){
    //while(1){

    int nums[9][9]={0};
    while(cin>>nums[0][0]){
        for(int i(1); i<9; ++i)cin>>nums[0][i];
        for(int i(1); i<9; ++i){
            //while(cin>>nums);
            for(int j(0); j<9; ++j)cin>>nums[i][j];
        }
        for(int i(0); i<9; ++i){
            for(int j(0); j<9; ++j){
                if(nums[i][j]==0)
                    nums[i][j]=insertFirstSutable(nums, i, j);
                else
                    continue;
            }
        }
        for(int i(0); i<9; ++i){
            for(int j(0); j<9; ++j)
                cout<<nums[i][j];
            cout<<endl;
        }
    }


}
