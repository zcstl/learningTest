#include "SingleName.h"
#include <iostream>
#include <stack>

/************************************************/
/**337. House Robber III*************************/
/************************************************/
int zcs::Leet337::rob(TreeNode* root)
{
    //该问题即树的breadth first搜索
    //自己的实现,未参考任何b-f算法
    //实现思路:通过奇数栈,偶数栈分别保存depth为奇数或偶数的node
    //然后for循环分别出栈入栈分别计算总和
    //但题意是求不相邻的层值的和的最大值
    //广度优先搜索,求得每层的节点和,得到一个数组,求不相邻的值的最大组合

    //root为NULL
    if(root==nullptr)
        return 0;

    std::vector<int> results;
    std::stack<TreeNode *> oddStack;
    std::stack<TreeNode *> evenStack;
    evenStack.push(root);
    int cycleCount=0;
    int oddTotal=0;
    int evenTotal=0;
    TreeNode* tmp;
    while(!oddStack.empty()||!evenStack.empty())
    {
        if (cycleCount==0)
        {
            while(!evenStack.empty())
            {
                //(evenStack.top()).val; error, operator.没有相关的重载,右操作数为*,需解引用 **
                //(evenStack.top())->val;
                //(*evenStack.top()).val;
                //.运算符为成员运算符, ->会将指针解引用
                tmp=evenStack.top();
                evenTotal+=tmp->val;
                //空指针也会占一栈,而不是被忽略,毕竟空指针也是个有内存的存在**
                if(tmp->left!=nullptr)
                    oddStack.push(tmp->left);
                if(tmp->right!=nullptr)
                    oddStack.push(tmp->right);
                evenStack.pop();
            }
            cycleCount=1;
            results.insert(results.end(),evenTotal);
            evenTotal=0;
        }
        else
        {
            while(!oddStack.empty())
            {
                tmp=oddStack.top();
                oddTotal+=tmp->val;
                if(tmp->left!=nullptr)
                    evenStack.push(tmp->left);
                if(tmp->right!=nullptr)
                    evenStack.push(tmp->right);
                oddStack.pop();
            }
            cycleCount=0;
            results.insert(results.end(),oddTotal);
            oddTotal=0;
        }
    }
    for(auto tmp=results.cbegin();tmp<=results.cend();++tmp)
        std::cout<<*tmp<<std::endl;
    return (oddTotal>evenTotal)?oddTotal:evenTotal;

}



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



