#include <iostream>
#include <SingleName.h>
#include <vector>
using namespace std;

int main()
{
    zcs::SingleName sn;
    vector<int> nums={6,1,11,1,2,2,5,5,6};
    int res=sn.singleNumber(nums);
    cout<<res<<endl;
}
