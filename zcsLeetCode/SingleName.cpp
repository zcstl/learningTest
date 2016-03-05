#include "SingleName.h"
int zcs::SingleName::singleNumber(std::vector<int>& nums)
{
    int tmp=0;
    int numsSize=nums.size();
    if(numsSize==1)
        return *nums.cbegin();
    //用前置省事省心
    auto numsLastOne=--nums.cend();
    for (auto iter=nums.cbegin();iter<numsLastOne;++iter)
        tmp=tmp^*iter^*++iter;
    //nums.erase(numsLastOne);
    tmp=tmp^*--nums.end();
    return tmp;
}

