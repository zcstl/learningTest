#include "SingleName.h"
#include <iostream>

/************************************************/
/**153. Find Minimum in Rotated Sorted Array*****/
/************************************************/
int zcs::Leet153::findMin(std::vector<int>& nums)
{
    // some pivot means one pivot
    //this povot may be in the position of cend,,,according to the test instance
    //1.不增加空间复杂度的前提下，比较好的实现
    //测试用例:  [1,2,3],[3,2,1],[3,1,2],[1,3,2],[2,3,1],[2,1,3]

    auto indexIter=nums.cbegin();
    int firstOne=*indexIter;
    if(nums.size()==1)
        return firstOne;
    int secondOne=*(indexIter+1);
    //
    if(nums.size()==2)
        return (firstOne<secondOne)?firstOne:secondOne;
    auto lastOne=*--nums.cend();
    //auto thirdOne=*(nums.cbegin()+2);
    //
    if((firstOne>secondOne)&&(secondOne<lastOne)&&(firstOne>lastOne))
        return secondOne;
    //
    if((firstOne<secondOne)&&(secondOne>lastOne)&&(firstOne<lastOne))
        return firstOne;
    auto penult=*--(--nums.cend());
    //
    if((firstOne>lastOne)&&(penult>lastOne)&&(firstOne<penult))
        return lastOne;
    //
    if((firstOne<lastOne)&&(penult<lastOne)&&(firstOne>penult))
        return penult;
    //
    if((firstOne>secondOne)&&(firstOne>lastOne))
        return lastOne;
    //
    if((firstOne<secondOne)&&(firstOne<lastOne))
        return firstOne;
    if(firstOne<=secondOne)
    {
        while((*indexIter)<*++indexIter);
        return *indexIter;
    }
    else
    {
        while((*indexIter)>*++indexIter);
        return *--indexIter;
    }

    //2.牺牲空间复杂度，缩小时间复杂度
    //有bug,单个元素
    /*
    nums.insert(nums.end(),nums.cbegin(),nums.cend());
    for(auto iter=nums.cbegin();iter<nums.cend();++iter)
        std::cout<<*iter<<std::endl;
    auto indexIter=nums.cbegin();
    if(*nums.cbegin()<=*(nums.cbegin()+1))
    {
        while((*indexIter)<*++indexIter);
        return *indexIter;
    }
    else
    {
        while((*indexIter)>*++indexIter);
        return *--indexIter;
    }
    */
    //3.最方便的实现，同时时间复杂度高
    /*
    auto indexIter=nums.cbegin();
    int tmp=*indexIter;
    ++indexIter;
    auto afterLast=nums.cend();
    while(indexIter<afterLast)
    {
        if(*indexIter<tmp)
            tmp=*indexIter;
        ++indexIter;
    }
    return tmp;
    */
}



/************************************************/
/**136. Single Number****************************/
/************************************************/
int zcs::SingleName::singleNumber(std::vector<int>& nums)
{
    int tmp=0;
    auto numsLastOne=--nums.cend();
    for (auto iter=nums.cbegin();iter<numsLastOne;++iter)
        tmp=tmp^*iter^*++iter;
    tmp=tmp^*numsLastOne;
    return tmp;
}

/*
int zcs::SingleName::singleNumber(std::vector<int>& nums)
{
    int tmp=0;
    //int numsSize=nums.size();
    if(nums.size()==1)
        return *nums.cbegin();
    //用前置省事省心
    auto numsLastOne=--nums.cend();
    for (auto iter=nums.cbegin();iter<numsLastOne;++iter)
        tmp=tmp^*iter^*++iter;
    //nums.erase(numsLastOne);
    //--nums.cend()  Consume much time
    tmp=tmp^*numsLastOne;
    return tmp;
}
*/


/************************************************/
/**292. Nim Game*********************************/
/************************************************/
bool zcs::NimGame::canWinNim(int n)
{
    return n%4!=0;
}
/*
bool canWinNim(int n)
{
    bool result=1;
    if (n%4==0)
        result=0;
    return result;
}
*/


/************************************************/
/**238. Product of Array Except Self*************/
/************************************************/
std::vector<int> zcs::Leet238::productExceptSelf(std::vector<int>& nums)
{
    int numsSize=nums.size();
    std::vector<int> res(numsSize);
    int comulatedMuti=1;
    int zerosNum=0;
    int zerosPosition=0;
    int i;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {
            zerosNum++;
            zerosPosition=i;
        }
        else
            comulatedMuti=comulatedMuti*nums[i];
    }
    if(zerosNum>=2)
        return res;
    else if(zerosNum==1)
        {
            res[zerosPosition]=comulatedMuti;
            return res;
        }
    for(i=0;i<numsSize;i++)
        res[i]=comulatedMuti/nums[i];
    return res;
}



/*
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size());
    int comulatedMuti=1;
    int zerosNum=0;
    int zerosPosition=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
        {
            zerosNum++;
            zerosPosition=i;
        }
        else
            comulatedMuti=comulatedMuti*nums[i];
    }
    if(zerosNum>=2)
        return res;
    else if(zerosNum==1)
        {
            res[zerosPosition]=comulatedMuti;
            return res;
        }
    for(int i=0;i<nums.size();i++)
        res[i]=comulatedMuti/nums[i];
    return res;
}
*/



