#include <iostream>
#include <SingleName.h>
#include <vector>
using namespace std;

int main()
{
    zcs::Leet153 sn;
    vector<int> nums={2,3,1};
    int res=sn.findMin(nums);
    //std::string str((res==1)?"yes":"no");
    cout<<res<<endl;

}
