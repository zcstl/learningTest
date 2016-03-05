#include "singleName.h"
int singleName::singleNumber(vector<int>& nums)
{
    int tmp=0;
    int numsSize=nums.size();
    if(numsSize==1)
        return *nums.cbegin();
    //nums.insert(nums.end(),0);
    auto numsLaseOne=nums.cend()--;
    for (auto iter=nums.cbegin();iter<numsLaseOne;iter++)
        tmp=(tmp^*iter)^*iter++;
    //nums.erase(numsLaseOne);
    tmp=tmp^(*nums.end()--);
    return tmp;
}
