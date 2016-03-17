#include "SingleName.h"
#include <iostream>
#include <stack>
#include <algorithm>
#include <memory.h>

using std::cout;
using std::endl;
/************************************************/
/**sort*************************/
/************************************************/
//debug,,,
void zcs::sortZCS::quickSort(int* nums, unsigned int n)
{
    if (nums==nullptr)
    {
        cout<<"nums is NULL"<<endl;
        return;
    }
    if (n==1)
        return;
    if (n==2)
    {
        if (*nums<*(nums+1))
            return;
        int tmp(*(nums+1));
        *(nums+1)=*nums;
        *nums=tmp;
    }
    int* sta(nums);
    int* end1(nums+n-1);
    recurSort(nums, sta, end1);
}

void zcs::sortZCS::recurSort(int* nums, int* sta, int* end1)
{
    int* su=getSu(nums, sta, end1);
    int* median=sortBySu(nums, sta, end1, su);
    if ((sta+1)<(median-1))
        recurSort(nums, sta, median-1);
    if ((median+1)<(end1))
        recurSort(nums, median, end1);
}

int* zcs::sortZCS::getSu(int* nums, int* sta, int* end1)
{
    return sta;
}

int* zcs::sortZCS::sortBySu(int* nums, int* sta, int* end1, int* su)
{
    while (sta<end1)
    {
        while (sta<=su)
            ++sta;
        while (end1>su)
            --end1;
        if ((sta-1)==end1)
        {
            int tmp(*su);
            *su=*(sta-1);
            *(sta-1)=tmp;
        }
        int tmp(*sta);
        *sta=*end1;
        *end1=tmp;
    }
    return su;
}

/************************************************/
/**337. House Robber III*************************/
/**note: 动态规划, 树的后序遍历与广度优先搜索********/
int zcs::Leet337::rob(TreeNode* root)
{
    /**分类:求出每个类的max,最后得出全局的max --> 动态规划+树的后序遍历**/
    if(root==nullptr)
        return 0;
    int* val;
    val=getMaxVal(root);
    int result=(val[0]>val[1])?val[0]:val[1];
    free(val);
    return result;
}

int* zcs::Leet337::getMaxVal(TreeNode* node)
{
    int* leftVal=(int*)malloc(2*sizeof(int));
    memset(leftVal,0,2*sizeof(int));
    int* rightVal=(int*)malloc(2*sizeof(int));
    memset(rightVal,0,2*sizeof(int));
    int* parentVal=(int*)malloc(2*sizeof(int));
    memset(parentVal,0,2*sizeof(int));
    if (node->left!=nullptr)
    {
        int* tmpValPtr;
        tmpValPtr=getMaxVal(node->left);
        leftVal[0]=*tmpValPtr;
        leftVal[1]=*(tmpValPtr+1);
        free(tmpValPtr);
    }

    if (node->right!=nullptr)
    {
        int* tmpValPtr;
        tmpValPtr=getMaxVal(node->right);
        rightVal[0]=*tmpValPtr;
        rightVal[1]=*(tmpValPtr+1);
        free(tmpValPtr);
    }

    if ((node->left==nullptr)&&(node->right==nullptr))
    {
        parentVal[0]=0;
        parentVal[1]=node->val;
        free(leftVal);
        free(rightVal);
        return parentVal;
    }
    parentVal[0]=std::max(leftVal[0],leftVal[1])+std::max(rightVal[0],rightVal[1]);
    parentVal[1]=leftVal[0]+rightVal[0]+node->val;
    free(leftVal);
    free(rightVal);
    return parentVal;
}




int zcs::Leet337::robNote(TreeNode* root)
{
    /**题意理解错了**/
    //该问题即树的breadth first搜索
    //自己的实现,未参考任何b-f算法
    //实现思路:通过奇数栈,偶数栈分别保存depth为奇数或偶数的node
    //然后for循环分别出栈入栈分别计算总和
    //但题意是求不相邻的层值的和的最大值
    //广度优先搜索,求得每层的节点和,得到一个数组,求不相邻的值的最大组合
    /**树的breadth first search**/
    /**动态规划**/ //m[i]=max(a[i]+m[i+2],m[i+1]),a为数组,m[i]为从a[i]算起的最大不相邻子数组

    //
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
    //vector to array
    int resultsSize=results.size();
    int money[resultsSize];
    auto tmp1=results.cbegin();
    for(int i=0;tmp1<results.cend();++i,++tmp1)
    {
            std::cout<<*tmp1<<std::endl;
            money[i]=*tmp1;
    }
    //
    return dynamicPro(money,resultsSize);

}

int zcs::Leet337::dynamicPro(int* money,int resultsSize)
{
    int m1=money[resultsSize-1];
    int m2=(money[resultsSize-2]>money[resultsSize-1])?money[resultsSize-2]:money[resultsSize-1];
    int tmp2=0;
    for(int i=resultsSize-3;i>=0;--i)
    {
        tmp2=m1;
        m1=((money[i]+m2)>m1)?(money[i]+m2):m1;
        m2=tmp2;
    }
    return m1;
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



