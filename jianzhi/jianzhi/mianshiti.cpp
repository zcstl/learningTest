#include "mianshiti.h"
#include <array>
#include <vector>
#include <memory.h>
#include <utility>
#include <math.h>
using namespace jzOffer;


/**
    数组中只出现一次的数字
    一个整形数组只有两个数字只出现了一次，其余数字都出现了两次
    提示：考虑只有一个数字只出现了一次的解法

    思路：
    1.暴力解决，两次遍历，，，O(n*n)
    2.考虑只有一个数字只出现了一次的解法，即抑或操作
    2.1.对于两个只出现一次的数字，若把数组分成两个子数组，每个子数组分别包含一个单独出现的数字，
    且成对的数字在同一组，便可解决。
    2.2.如何拆分数组？原数组抑或一边后为两个数抑或的结果，找出第一个为1的bit，按该bit是否为1拆分数组。
**/

/**
    大数运算

    思路：
    数组模拟，倒序模拟，优化：10000进制
**/
/**大数相乘**/
/*
void twoNumAdd(string& a, string& b);

int main(){
    //
    string a, b;
    cin>>a>>b;
    //
    unsigned char aSize=a.size(), bSize=b.size();
    for(int i(0); i<aSize; ++i)
        if(a[i]<'0' && a[i]>'9'){
            cout<<"Bad input!"<<endl;
            return -1;
        }
    for(int i(0); i<bSize; ++i)
        if(b[i]<'0' && b[i]>'9'){
            cout<<"Bad input!"<<endl;
            return -1;
        }
    //
    int maxLen(0), strLen(0), mutiTimes(0);
    if(aSize>bSize)
        maxLen=aSize, strLen=aSize*2, mutiTimes=bSize;
    else
        maxLen=bSize, strLen=bSize*2, mutiTimes=aSize, a.swap(b);

    //a*b
    string tmp(strLen, '0'), res(strLen, '0'), tmpTmp=tmp;
    for(int i(mutiTimes-1); i>=0; --i){
        int pushNum(0), s1(0), s2(0), xj(0);
        for(int j(maxLen-1); j>=0; --j){
            s1=a[j]-'0', s2=b[i]-'0', xj=s1*s2;
            //cout<<maxLen+j+(i-mutiTimes+1)<<endl;
            //cout<<(tmp[maxLen+j+(i-mutiTimes+1)]=(xj+pushNum)%10+'0')<<endl;
            tmp[maxLen+j+(i-mutiTimes+1)]=(xj+pushNum)%10+'0';
            pushNum=(xj+pushNum)/10;
        }
        tmp[maxLen-1-(mutiTimes-1-i)]=pushNum+'0';
        //cout<<tmp<<endl;
        twoNumAdd(res, tmp);
        tmp=tmpTmp;
    }
    cout<<res.substr(res.rfind('0')+1)<<endl;
}

void twoNumAdd(string& a, string& b){
    int pushNum(0), s1(0), s2(0), xj(0);
    for(int i(a.size()-1); i>=0; --i){
        s1=a[i]-'0', s2=b[i]-'0', xj=s1+s2;
        a[i]=(xj+pushNum)%10+'0';
        pushNum=(xj+pushNum)/10;
    }
}
*/


/**
    格雷码

    1.找规律，抓住对称性，下标计算，非递归实现
    1.1.重构代码，最好把下标操作简化,找bug
    2.**数学规律，从0到n，每个数字与其右移一位后的值做抑或

    细节：getGreyCode有两个bug，要注意！！！
**/
void GreyCode::getGreyCodePlus(int n){
    if(n<1)return;
    for(int i(0); i<pow(2,n); ++i)
        printf("%d\n", i^i>>1);
}

int* GreyCode::getGreyCode(int n){
    if(n<1)return nullptr;
    int rowN=pow(2, n);
    char** res=new char*[rowN];
    for(int i(0); i<rowN; ++i)
        res[i]=new char[n+1], memset(res[i], '0', sizeof(char)*(n+1)), res[i][n]='\0';
    /**%%memset(res[i], 0, sizeof(char)*(n+1)); ASCII中0表示NULL，也就是'\0'%%**/
    res[0][n-1]='0', res[1][n-1]='1';
    //
    for(int i(1); i<n; ++i)
        for(int j=pow(2, i), m=1, th=pow(2, i+1); j<th; ++j, m+=2){
            strcpy(res[j], res[j-m]);
            res[j][n-1-i]='1';
        }
    int* resNum=new int[rowN];
    memset(resNum, 0, sizeof(int)*rowN);

    swtichToNum(resNum, res, n);
    for(int i(0); i<rowN; ++i)
        delete[]res[i];
    for(int i(0); i<rowN; ++i)printf("%d\n", resNum[i]);
        return resNum;
}

void GreyCode::swtichToNum(int *resNUm, char** res, int n){
    int rowN=pow(2, n);
    for(int i(0); i<rowN; ++i)
        for(int j(n-1); j>=0; --j)
            /**resNUm[i]+=res[i][j]*pow(2, n-1-j);  res[i][j]是一个char，'1'不为1**/
            resNUm[i]+=(res[i][j]-'0')*pow(2, n-1-j);
}
/**
    计算二叉树的深度
    判断二叉树是否平衡

    思路：
    1.计算深度，递归实现就是前序遍历的改版
    2.计算深度，若非递归实现，计算层数便可以，广度优先遍历
    使用vector保存每层节点信息，读完一层节点后，入一个flag，当下标为vector大小减1时，终止循环
    2.1.也可以把root节点和一个标记放进queue，出队，依次放入左右节点，出队为flag层数加1，然后入队flag，
    若queue的大小出队前为0，则break

    3.判断是否平衡：递归到从底部开始到root节点，计算高度并判断是否平衡
    小细节：需要传递返回两个值（bool和树的高度），指针传参实现
**/
bool Ti39::isBinaryTreeBalance(binaryTreeNode* t){
    if(t==nullptr){
        printf("Bad input!");
        return false;
    }
    int h(0);
    return _isBinaryTreeBalance(t, &h);
}

bool Ti39::_isBinaryTreeBalance(binaryTreeNode* t, int* pH){
    if(t==nullptr){
        *pH==0;
        return true;
    }
    int pHL(0), pHR(0);
    if(_isBinaryTreeBalance(t->pLeft, &pHL) && _isBinaryTreeBalance(t->pRight, &pHR))
        if(pHL-pHR!=2 && pHL-pHR!=-2){
            *pH=pHL>pHR?pHL:pHR+1;
            return true;
        }
    return false;
    /*
    bool isR=_isBinaryTreeBalance(t->pRight, &pHL);
    bool isL=_isBinaryTreeBalance(t->pLeft, &pHR);
    if(pHL-pHR==2 || pHL-pHR==-2)
        return false;
    *pH=pHL>pHR?pHL:pHR+1;
    return isR&&isL;
    */
}

int Ti39::heightOfBinaryTree(binaryTreeNode* t){
    if(t==nullptr)
        return -1;
    vector<binaryTreeNode*> nodes(1000);
    binaryTreeNode* flag;
    flag->pLeft==nullptr, flag->pRight=nullptr;
    int res(0);
    nodes.push_back(t);
    nodes.push_back(flag), ++res;
    int index(0);
    while(index< (nodes.size()-1)){
        if(nodes[index]->pLeft!=nullptr)
            nodes.push_back(nodes[index]->pLeft);
        if(nodes[index]->pRight!=nullptr)
            nodes.push_back(nodes[index]->pRight);
        if(nodes[index++]==flag)
            nodes.push_back(flag), ++res;
    }
    return res;
}


/**
    找到两个链表第一个公共节点，链表为普通链表

    思路：
    遍历两个链表，把地址赋给指针数组，然后往后遍历两个数组，找到第一个不同值的下标，其后一个便是。
    如何把指针变量的值当做int赋值给int？
**/
listNode* Ti37::findFirstCommonNodeFrom2Lists(listNode* l1, listNode* l2){
    if(l1==nullptr || l2==nullptr){
        printf("Bad inputs!!");
        return nullptr;
    }
    //32bit 用int存储地址， 64bit则用long long
    int i(0), len1(0), len2(0);
    listNode* tmpPtr(nullptr);
    for(tmpPtr=l1; tmpPtr!=nullptr; tmpPtr=tmpPtr->pNext)++len1;
    listNode** arr1=new listNode*[len1];
    for(tmpPtr=l1, i=0; tmpPtr!=nullptr; tmpPtr=tmpPtr->pNext)arr1[i++]=tmpPtr;
    //
    for(tmpPtr=l2, i=0; tmpPtr!=nullptr; tmpPtr=tmpPtr->pNext)++len2;
    listNode** arr2=new listNode*[len2];
    for(tmpPtr=l2, i=0; tmpPtr!=nullptr; tmpPtr=tmpPtr->pNext)arr2[i++]=tmpPtr;
    //
    i=-1;
    for(int m(len1-1), n(len2-1); m>=0 && n>=0; --m, --n)
        if(arr1[m]!=arr2[n]){
            i=m;
            break;
        }
    delete []arr1;
    delete []arr2;
    if(i!=-1)
        return arr1[++i];
    else
        return nullptr;
}

/**
    计算数组中逆序对的个数

    思路：
    1.暴力解决，两个for循环，t.O(n*n)
    2.使用归并排序，t.O(nlogn), 思路：分解，合并的过程中先统计逆序对数目，再合并

**/
int Ti36::countInversePairs(int* nums, int low, int high){
    if(nums==nullptr || low<0 || high<low){printf("bad input!!");return -1;}
    //
    count_=0;
    int* tmp=new int[high-low+1];
    memset(tmp, 0, sizeof(int)*(high-low+1));
    int* numsTmp=new int[high-low+1];
    for(int i(low), j(0); i<=high; ++i, ++j)numsTmp[j]=nums[i];
    //
    countInversePairs_(numsTmp, tmp, 0, high-low);
    for(int i(0); i<high-low+1; ++i)printf("%d ", numsTmp[i]);
    printf("\n%d\n", count_);
    return count_;
}
/**分解**/
void Ti36::countInversePairs_(int* nums,int* tmp, int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        countInversePairs_(nums, tmp, low, mid);
        countInversePairs_(nums, tmp, mid+1, high);
        merge_(nums, tmp, low, mid, high);
    }
}
/**归并**/
void Ti36::merge_(int* nums, int* tmp,int low, int mid, int high){
    //
    for(int i(low); i<=high; ++i)tmp[i]=nums[i];
    /**统计逆序对和两路归并排序操作分开，无法同时完成**/
    for(int i(low); i<=mid; ++i)
        for(int j(mid+1); j<=high; ++j)
            if(nums[i]>nums[j])
                ++count_;
            else
                break;
    //
    int i(low), j(mid+1), m(low);
    //
    for( ; i<=mid && j<=high; ++m){
        if( tmp[i]<=tmp[j])
            nums[m]=tmp[i], ++i;
        else
            nums[m]=tmp[j], ++j;
    }
    //
    while(i<=mid)nums[m++]=tmp[i++];
    while(j<=high)nums[m++]=tmp[j++];
}


/**
    第一个只出现一次的字符
**/


/**
    丑数
**/



/**
    把数组排成最小的数，输入一个数组，输出该数组能够排列成一个数字的min

    思路：
    1.逐个选出最高位最小的数字作为目的值的高位，若两个数最高位相同，依次比较次高位
    1.1.一下实现可以完成123， 23， 3这种情况，但3， 32， 321便不行，若改正则比较麻烦
    2.

    宏定义的学习
**/
#define convertToStringJzOfferTi33(b, a)     \
{   tmp=b, index=0;     \
    while(tmp){a[index]=tmp%10; tmp/=10;}   \
    for(int i(0), j(a.size()); i<j; ++i, --j){  \
            swap(a[i], a[j]);\
    }   \
}

int Ti33::smallestNumsArrPermutation(int* nums, int len){
    if(nums==nullptr || len<1){
        printf("Bad input!!");
        return -1;
    }
    int* resNums=new int[len];
    char* flag=new char[len];
    int res(0);
    for(int i(0), minTmp(0); i<len; ++i){
        for(int j(0); j<len; ++j){
            minTmp=getHighMinOf2(nums, flag, minTmp, j);
        }
        flag[minTmp]=1;
        resNums[i]=nums[minTmp];
        //findSamllest(nums, flag, len);
        printf("%d",resNums[i]);
    }
    printf("\n");
    delete []flag;
    delete []resNums;
    return res;//
}

int Ti33::getHighMinOf2(const int* const &nums, char* const &flag, int minTmp, int j){
    if(flag[j]==1)
        return minTmp;
    else if(flag[minTmp]==1)
        return j;
    if(nums[j]==nums[minTmp])
        return j;
    string a, b;
    int tmp, index;
    convertToStringJzOfferTi33(nums[minTmp], a);
    convertToStringJzOfferTi33(nums[j], b);
    //
    int siz=a.size()>b.size()?b.size():a.size();
    for(int i(0); i<siz; ++i){
        if(a[i]<b[i]){
            flag[minTmp]=1;
            return minTmp;
        }else if(a[i]>b[i]){
                flag[j]=1;
                return j;
        }
    }
    return minTmp;
}

/**
    1到N这N个数字中1出现的次数

    思路：
    1.对1到N共N个数字进行分析，逐个累加1的个数，判断一的个数模10除10便行；t O(nlogn)
    2.严密的数学思维能力，找出规律，，，找出该规律很难
**/


/**
    求子数组最大和

    思路：
    1.分析子数组从begin位置开始，逐个求最大值的过程，会发现求值的规律；
    2.使用DP，用f(i)表示以第i个元素结尾的子数组的最大和,把以每个元素结尾的子数组的最大和求出来，
    最大值便是该数组的子数组最大值。
    两种思路异曲同工
**/
int Ti31::getMaxChildArray(int* nums, int len){
    if(nums==nullptr || len<1){
        printf("Bad input or null ptr!!");
        return -1;
    }
    int maxValue(0), flag(0), partMax(0);
    for(int i(0); i<len; ++i){
        if(partMax<0)
            partMax=nums[i];
        else
            partMax+=nums[i];
        if(partMax>=maxValue)
            maxValue=partMax, flag=1;
    }
    if(flag==1)
        return maxValue;
    else
        return nums[0];
}

/**
    最小的k个数

    思路：
    1.快排的多次partition求第k大的数，其左边就是最小的k个数
**/

void Ti30::getSmallestNums(int* nums, int len, int n, int(*func)(int*, int, int)){
    if(nums==nullptr || func==nullptr || len<1 || n<1)
        return;
    getSmallestNums_(nums, 0, len-1, n, func);
    for(int i(0); i<n; ++i)
        printf("%d ", nums[i]);
    printf("\n");
}

void Ti30::getSmallestNums_(int* nums, int low, int high, int n, int(*func)(int*, int, int)){
    int mid=Partition(nums, low, high, func);
    if(mid>n)
        getSmallestNums_(nums, low, mid-1, n, func);
    else if(mid<n)
            getSmallestNums_(nums, mid+1, high, n, func);
            else
                return;
}

int Ti30::Partition(int* nums, int low, int high, int(*func)(int*, int, int)){
    int pivotPos=func(nums, low, high);
    int pivot=nums[pivotPos];/**保存枢纽元数值，且枢纽元保存在first位置时，先从high开始，最后下标的位置便是枢纽元的位置**/
    swap(nums[low], nums[pivotPos]);
    while(low<high){
        while(nums[high]>=pivot && low<high)--high;
        swap(nums[high], nums[low]);
        while(nums[low]<=pivot && low<high)++low;
        swap(nums[low], nums[high]);
    }
    swap(nums[low], pivot);
    return low;
}

/**
    数组中出现次数超过一半的数字

    思路：
    1.超过一半的数字，一次遍历数组，维护两个变量即可
    2.基于快速排序的多次partition，可以O(n)得到任意第k大的数字，
    超过一半的数字，即第n/2大的数字。

    **细节：检查是否为超过一般的数字,传达这种错误信息可以用过返回值，全局变量或异常实现
**/
int Ti29::moreThanHalfNum(int * nums, int len){
    if(nums==nullptr || len<1)
        return -1;  //
    int n(nums[0]);
    for(int i(0), c(0); i<len; ++i)
        if(nums[i]==n)
            ++c;
        else if(--c==0)
                n=nums[i], ++c;
    //check
    int total(0);
    for(int i(0); i<len; ++i)
        if(nums[i]==n)++total;else --total;
    if(total<1)n=-1, printf("Don't have!!");
    return n;
}

/**
    字符串的排列
    输入一个字符串，打印出该字符串的所有排列

    思路：
    1.用一个char[256]数组保存某元素是否被打印的信息，然后for循环，递归，但重复元素没有考虑，
    @1为为考虑dup元素的代码实现
    2.
**/


/*@1
void Ti28::charPermutation(char* a, int len){
    if(a==nullptr || len<1)
        return;
    char isDup[256]={0};
    int pLen(0);
    charPermutation_(a, len, isDup, pLen);
}

void Ti28::charPermutation_(char* a, int len, char* & isDup, int pLen){
    for(int i(0); i<len; ++i)
        if(isDup[a[i]]==0)
            isDup[a[i]]=1, printf("%c ", a[i]), ++pLen, charPermutation_(a, len isDup, pLen);
        else if(pLen==len)
            printf("\n");
}
*/
/**
    将bst转换为双向链表，要求只能调整树节点的指针

    思路：
    以下两种方法时间复杂度在同一个量级，但第一个的系数理论上低一些
    1.自己的实现，基于中序遍历，引入改变指针的操作，但由于左右子树返回的值不同，
    左子树返回大值，右子树返回最小值，故写两个函数递归；
    1.1.处于函数栈消耗的考虑，可以改为非递归形式；

    2.基于中序遍历，维护一个指针，其指向已经建立好的链表的最后一个元素
**/
binaryTreeNode* Ti27::bstToDoubleList(binaryTreeNode* t){
    if(t==nullptr)return nullptr;
    auto left=bstToDoubleList(t->pLeft);
    exchange(left, t);
    auto right=bstToDoubleListRight(t->pRight);
    exchange(t, right);
    if(right==nullptr)
        return t;
    else
        return right;
}

binaryTreeNode* Ti27::bstToDoubleListRight(binaryTreeNode* t){
    if(t==nullptr)return nullptr;
    auto left=bstToDoubleList(t->pLeft);
    exchange(left, t);
    auto right=bstToDoubleListRight(t->pRight);
    exchange(t, right);
    if(left==nullptr)
        return t;
    else
        return left;
}

void Ti27::exchange(binaryTreeNode* a, binaryTreeNode* b){
    if(a==nullptr || b==nullptr)
        return;
    a->pRight=b;
    b->pLeft=a;
}

/**
    复杂链表的复制，node中有一个指针，可以指向任意节点或者为nullptr

    细节：pSibling可以指向自己

    思路：
    1.以标准链表的copy为基础，用一个vactor<pair<Node*, Node*>>维护旧节点和新节点的地址，每复制一个节点，先查找该vector是否已经创建过，
    若没有则创建node，并push_back；并且查看slibling是否在该vector中，没有则创建并压入；
    t.O(n*n),但系数比第二个小，然并卵

    2.一般的思路：先按照一般的链表copy，然后从头开始，每跟新一个slibling遍历原链表和新链表一次，t为O(n*n);

    **3.先按照一般链表进行copy，只不过产生形如，a-a'-b-b'-c-c'的结构，a为旧链表，a'为新链表，然后更新slibling也会更加
    方便。分解为如下三个子问题：产生该结构链表，更新slibling，拆分链表。t为O(n)。
**/
ComplexListNode* Ti26::clone(ComplexListNode* n){
    if(n==nullptr)return nullptr;
    //处理第一个节点
    ComplexListNode* pOld(nullptr), *pAhead(nullptr), *res(nullptr), *tmp(nullptr), **temp(&tmp);
    vector<pair<ComplexListNode*, ComplexListNode*>> nodes;
    nodes.resize(100);
    pAhead=res=new ComplexListNode;
    pAhead->val=n->val;
    pOld=n->pNext;
    nodes.push_back(make_pair(n, pAhead));
    //第一个节点的sibling
    if(n->pSibling!=nullptr)
        if(n->pSibling!=n){
            tmp=new ComplexListNode;
            tmp->val=n->pSibling->val;
            pAhead->pSibling=tmp;
            nodes.push_back(make_pair(n->pSibling, tmp));
        }else
            n->pSibling=n;
    //循环处理每个节点
    while(pOld!=nullptr){
        if(isContain(nodes, pOld, temp))
            pAhead->pNext=tmp, pAhead=tmp, pOld=pOld->pNext;
        else{
            tmp=new ComplexListNode;
            tmp->val=pOld->val;
            pAhead->pNext=tmp, pAhead=tmp, pOld=pOld->pNext;
            nodes.push_back(make_pair(pOld, tmp));
        }
        if(pAhead->pSibling!=nullptr)
            if(!isContain(nodes, pAhead->pSibling, temp))
            {
                tmp=new ComplexListNode;
                tmp->val=n->pSibling->val;
                pAhead->pSibling=tmp;
                nodes.push_back(make_pair(n->pSibling, tmp));
            }else
                pAhead->pSibling=tmp;
    }
    //
    pAhead->pNext==nullptr;
    return res;
}

bool Ti26::isContain(vector<pair<ComplexListNode*, ComplexListNode*>>& nodes, ComplexListNode* o, ComplexListNode** n){
    for(auto tmp: nodes)
        if(tmp.first==o){
            *n=tmp.second;
            return true;
        }
    return false;
}

/**
    打印二叉树中和为某个值的路径，路径指root到leaf途径节点；

    思路：
    通过前序遍历寻找路径，使用vector保存路径信息，节点的push和pop相当于当做stack,
    打印相当于当做array使用。
**/
//@1
bool jzOffer::ti25::findPath(jzOffer::binaryTreeNode* a, int n){
    if(a==nullptr)
        return false;
    vector<int> path;
    path.resize(100);
    return findPath_(a, n, path);
}
bool jzOffer::ti25::findPath_(jzOffer::binaryTreeNode* a, int n, vector<int>& path){
    int val=a->val;
    if(val>n)
        return false;
    path.push_back(val);
    if(val==n)
        if(a->pLeft==nullptr && a->pRight==nullptr){
            for(auto tmp: path)
                printf("%d ", tmp);
            printf("\n");
            path.pop_back();
            return true;
        }else{
            path.pop_back();
            return false;
        }
    else{
        n-=val;
        bool left=a->pLeft!=nullptr&&findPath_(a->pLeft, n, path);
        bool right=a->pRight!=nullptr&&findPath_(a->pRight, n, path);
        path.pop_back();
        return left||right;
    }
}
/**
    从上往下打印二叉树

    queue与deque的api不同，前者与stack相似但不同
    注意以下程序中判断条件的优化
**/
void jzOffer::ti23::printBSTFromUpToDown(jzOffer::binaryTreeNode* t){
    if(!t)
        return;
    queue<jzOffer::binaryTreeNode*> tmp;
    tmp.push(t);
    while(tmp.size()){
        t=tmp.front(), printf("%d ",t->val), tmp.pop();
        if(t->pLeft)
            tmp.push(t->pLeft);
        if(t->pRight)
            tmp.push(t->pRight);
    }
}
/**
    包含min函数的栈，使得pop，push和min都为O(1)

    使用辅助栈，入栈保存当前最小值
    类模板实现
**/

/**
    顺时针打印矩阵
**/
/**
    返回二叉树的镜像

    1.题意理解错误，把镜像理解成拷贝，这个得和面试官沟通，
    看是否是镜子里的像的意思,还得确定是否在原来树结构中改变
    2.要熟悉前序和中序遍历的非递归实现
**/
jzOffer::binaryTreeNode* jzOffer::ti19::getBinaryTreeImage(jzOffer::binaryTreeNode* t){
    if(t==nullptr)
        return nullptr;
    //jzOffer::binaryTreeNode* node=new jzOffer::binaryTreeNode;
    //node->val=t->val;
    jzOffer::binaryTreeNode* tmp=t->pLeft;
    t->pLeft=getBinaryTreeImage(t->pRight);
    t->pRight=getBinaryTreeImage(tmp);
    return t;
}
/*
jzOffer::binaryTreeNode* jzOffer::ti19::getBinaryTreeImage(jzOffer::binaryTreeNode* t){
    if(t==nullptr)
        return nullptr;
    jzOffer::binaryTreeNode* node=new jzOffer::binaryTreeNode;
    node->val=t->val;
    node->pLeft=getBinaryTreeImage(t->pLeft);
    node->pRight=getBinaryTreeImage(t->pRight);
    return node;
}*/
/**
    判断二叉树b是否是二叉树a的子树

    重点是鲁棒性，空指针的判断，防御性编程
    1.常规实现，先序遍历找到等于b的根节点的节点，每找到一个节点，需要调用函数判断是否为子树

    2.自己的实现：将先序遍历和判断相同节点子节点是否相同柔和在一起咯 :）
**/
//a b都不为空，判断是否子树才有意义
bool jzOffer::ti18::isChildTree(jzOffer::binaryTreeNode* a, jzOffer::binaryTreeNode* b){
    if(a!=nullptr && b!=nullptr)
        return isChildTree_(a, b);
    return false;
}

bool jzOffer::ti18::isChildTree_(jzOffer::binaryTreeNode* a, jzOffer::binaryTreeNode* b){
    if(b==nullptr)
        return true;
    else if(a==nullptr)
            return false;
    if(a->val==b->val)
        if(isChildTree(a->pLeft, b->pLeft) && isChildTree(a->pRight, b->pRight))
            return true;
    return isChildTree(a->pLeft, b) || isChildTree(a->pRight, b);
}
/**
    合并两个排序的链表

    1.指针操作，留意空指针，鲁棒性
    2.递归实现代码更为简洁，但递归有递归的缺点

    3.此处形参用listNode** pL1没有价值还增加代码量
**/
//递归实现
jzOffer::listNode* jzOffer::ti17::mergeSortedListV1(jzOffer::listNode* pL1, jzOffer::listNode* pL2){
    if(pL1==nullptr)
        return pL2;
    else if(pL2==nullptr)
        return pL1;

    jzOffer::listNode* pAhead(nullptr);
    if(pL1->val < pL2->val){
        pAhead=pL1;
        pAhead->pNext=mergeSortedListV1(pL1->pNext, pL2);
    }else{
        pAhead=pL2;
        pAhead->pNext=mergeSortedListV1(pL1, pL2->pNext);
    }
    return pAhead;
}

//循环实现
jzOffer::listNode* jzOffer::ti17::mergeSortedList(jzOffer::listNode** pL1, jzOffer::listNode** pL2){
    if(pL1==nullptr || *pL2==nullptr)
        if(pL2==nullptr || *pL2==nullptr)
            return nullptr;
        else
            return *pL2;
    else if(pL2==nullptr || *pL2==nullptr)
            return *pL1;

    jzOffer::listNode* p1(*pL1), *p2(*pL2), *pBefo, *pList;
    if(p1->val < p2->val)
        pBefo=p1, p1=p1->pNext;
    else
        pBefo=p2, p2=p2->pNext;
    pList=pBefo;
    while(p1!=nullptr && p2!=nullptr){
        if(p1->val < p2->val)
            pBefo=p1, p1=p1->pNext;
        else
            pBefo=p2, p2=p2->pNext;
    }
    if(p1==nullptr)
        pBefo->pNext=p2;
    else
        pBefo->pNext=p1;
    return pList;
}

/**
    反转链表

    需三个指针分别指向当前节点，前驱及后继节点
    1.递归实现的版本
**/
jzOffer::listNode* jzOffer::ti16::rotateList_(jzOffer::listNode* pL, jzOffer::listNode** pTail){
    if(pL->pNext==nullptr){
        *pTail=pL;
        return pL;
    }
    jzOffer::listNode* pBehind=rotateList_(pL->pNext, pTail);
    pBehind->pNext=pL;
    return pL;
}
jzOffer::listNode* jzOffer::ti16::rotateListV1(jzOffer::listNode* pL){
    if(pL==nullptr)
        return nullptr;
    jzOffer::listNode *tail(nullptr), **pTail(&tail);//
    rotateList_(pL, pTail);
    pL->pNext==nullptr;
    return tail;
}

jzOffer::listNode* jzOffer::ti16::rotateList(jzOffer::listNode* pL){
    if(pL==nullptr)
        return nullptr;
    jzOffer::listNode* pBehind(pL->pNext), *tmp;
    pL->pNext=nullptr;
    while(pBehind!=nullptr)
        tmp=pBehind->pNext, pBehind->pNext=pL, pL=pBehind, pBehind=tmp;
    return pL;
}


/**
    返回/删除链表倒数第k个节点
    此处主要考察代码的鲁棒性

    1.若仅仅返回倒数第k个节点，形参为listNode* pList便可以
    2.仅返还倒数第k个节点的函数比删除的代码量少一半；

    **3.两个指针，一快一慢遍历链表。 如求链表的中间节点，判断单向链表是否成环
**/
jzOffer::listNode* jzOffer::ti15::getTheLastKthNode(jzOffer::listNode** pList, int k){
    if(pList==nullptr || *pList==nullptr || k<1)
        return nullptr;
    //1
    jzOffer::listNode* pBefo(*pList), *ptr(*pList), *tmp;
    int countNode(0);
    while(ptr!=nullptr && countNode!=k+1)
        ptr=ptr->pNext, ++countNode;

    if(ptr==nullptr && countNode<k)
        return nullptr;
    if(ptr==nullptr && countNode==k){
        tmp=*pList;
        *pList=(*pList)->pNext;
        delete tmp;
        tmp=nullptr;
        return nullptr;
    }
    //2
    while(ptr!=nullptr)
        ptr=ptr->pNext, pBefo=pBefo->pNext;
    tmp=pBefo->pNext;
    pBefo->pNext=pBefo->pNext->pNext;
    delete tmp;
    tmp=nullptr;
}

/**
    调整数组顺序使得奇数位于偶数前面，odd，even

    1.一般做法，类似于quickSort的一趟partition
    2.考虑可扩展性（代码的可重用性）的做法：将拆分数组操作和判断标准实现解耦合
    传入函数指针，(bool)(*func)(int);当然可以进一步把数组
    元素泛化。
**/


void jzOffer::ti14::adjustArrayToApartOdd(int* arr, int len){
    if(arr==nullptr || len<1)
        return;
    int low(0), high(len-1);
    while(low<high){
        while((arr[low]&1)==1 && low<high)++low;
        while((arr[high]&1)==0 && low<high)--high;
        swap(arr[low], arr[high]);
    }
    for(int i(0); i<len; ++i)
        printf("%d ",arr[i]);
    printf("\n");
}


/**
    以O(1)时间删除pToBeDeleted指向链表的节点

    删除链表节点的两种实现,且都考虑了待删除节点不在链表中
**/
//O(1)删除非尾节点
void deleteNode(jzOffer::listNode** pListHead, jzOffer::listNode* pToBeDeleted){
    if(pListHead==nullptr || *pListHead==nullptr || pToBeDeleted==nullptr)
        return;

    jzOffer::listNode* ptr=*pListHead;
    //删除节点是否为头节点
    if(ptr==pToBeDeleted){
        *pListHead=ptr->pNext;
        delete pToBeDeleted;
        return;
    }//是否为尾节点(此处代码实现要求是非头节点)
    if(pToBeDeleted->pNext==nullptr){
        while(ptr->pNext!=pToBeDeleted && ptr!=nullptr)
            ptr=ptr->pNext;
        if(ptr==nullptr)//考虑了待删除节点不在链表中
            return;
        ptr->pNext==nullptr;
        delete pToBeDeleted;
        return;
    }//非尾节点,非头节点
    ptr=pToBeDeleted->pNext;
    if(ptr!=nullptr){//考虑了待删除节点不在链表中,但这样会埋下乱删除节点的隐患
        pToBeDeleted->val=ptr->val;
        pToBeDeleted->pNext=ptr->pNext;
        delete ptr;
    }

}

//O(n),顺序遍历
/*
void deleteNode(jzOffer::listNode** pListHead, jzOffer::listNode* pToBeDeleted){
    if(pListHead==nullptr || *pListHead==nullptr || pToBeDeleted==nullptr)
        return;
    jzOffer::listNode* ptr=*pListHead;
    if(ptr==pToBeDeleted){
        *pListHead=ptr->pNext;
        delete pToBeDeleted;
    }else{
        while(ptr->pNext!=nullptr){
            if(ptr->pNext==pToBeDeleted)
                break;
            ptr=ptr->pNext;
        }
    }
    if(ptr->pNext!=nullptr){
        ptr->pNext=ptr->pNext->pNext;
        delete pToBeDeleted;
    }
}
*/


/**
    打印1到最大的n位数

    1.大数问题:数组或字符串表示
    2.注意程序中判断溢出n位数的方法,和打印n位数的方法

    3.此题也可以用递归实现全排列,但t上没啥优势

    延伸:1.大数相加,得考虑正负; 2.大数相乘
**/
int jzOffer::ti12::print1ToMaxN(int n){
    if(n<0) return -1;
    if(n==0) return 0;

    char* res=new char[n];
    memset(res, 0, sizeof(char)*n), ++res[n-1];
    bool isContiune(true), isZero(true);
    /**
        isContinue当数字超出n位数时为false
        isZero为true表示res[i]为前部份0
    **/
    while(isContiune){
        for(int i(0); i<n; ++i){
            if(res[i]!=0 || !isZero){
                isZero=false;
                printf("%d", (int)res[i]);
            }
        }
        printf("\n"), isZero=true;
        addOne(res, n, isContiune);
    }
    delete []res;
    return 0;
}

inline void jzOffer::ti12::addOne(char * res, int& len, bool& isCon){
    /**
        产生进位,isPush为true,当res[0]产生进位,i为-1,isCon为false,退出while循环
    **/
    bool isPush(false);
    int i=len-1;
    do{
        if((res[i]++)==9)
            isPush=true, res[i]=0, --i;
        else
            isPush=false;
    }
    while(isPush && i>-1);
    if(i==-1)
        isCon=false;
}

/**
    求一个数的整数次方,不用考虑大数

    要点:
    1.功能测试: 次数为负数要考虑etc
    2.边界测试: 0的0次在数学上没有意义,返回0和1都可以接受
    3.负面测试: 0的负数次, 通过返回值,或全局变量或异常来传达信息
    细节:
    1.计算机表示小数都有误差,如果两个数字的差的绝对值很小(如0.0000001)则认为这两个数相等
    2.位运算效率远高于除和模运算,除2用右移代替,模2用与1与运算代替
**/
double jzOffer::ti11::power(double base, int expo){
    if(equa(base, 0) && expo<0){isValidInput=false; return -1;}
    isValidInput=true;
    if(equa(base, 0))return 0; //0的0次也返回0

    double res(1);
    int expoTmp(expo);
    if(expoTmp<0)
        expoTmp=-expoTmp;
    res=curPower(base, expoTmp);
    if(expo<0)
        return 1/res;
    return res;
}

bool jzOffer::ti11::equa(int a, int b){
    if(a-b<0.0000001 && a-b>-0.0000001)
        return true;
    return false;
}

double jzOffer::ti11::curPower(double base, int expo){
    if(expo==0)
        return 1;
    double res=curPower(base, expo>>1);
    res*=res;
    if(expo&1 == 1)
        res*=base;
    return res;
}

/*功能测试未通过
double powerZCS(double base, int exponent){
    //if(exponent<0){printf("Bad exponent!\n"), return 0;}
    if(base==0)return 0;
    if(exponent==0)return 1;
    if(exponent==1)return base;
    if(exponent==-1)return 1/base;

    int res(base);
    int expTmp(exponent);
    if(expTmp<0)expTmp=-expTmp;
    while(expTmp!=1){
        res*=res;
        expTmp/=2;
    }
    if(exponent%2==1)
        res*=base;
    if(exponent<0)return 1/res;
    return res;
}
*/
/**
    输入一个整数,输出该整数二进制表示中1的个数
    注:负数补码表示,不是原码表示

    原码->补码:取反加1,符号位不变
    补码->原码:取反加1,符号位不变
    取反操作符:~, 符号位也会改变

    考虑到负数的情况:1.与a=1进行与操作,然后与左移一位的a进行与操作,,,
    2.(n-1)&n,则最右边的1会成为0
**/
/*输入负数则计算出错
int jzOffer::ti10::numberOfOne(int n){
    int times(0);
    //if(n<0)n=-n, ++times;  原码表示时
    //if(n<0)n=~n+1;
    while(n>0){
        times+=n&1;
        n=n>>1;
    }
    return times;
}
*/

int jzOffer::ti10::numberOfOne(int n){
    int times(0);
    while(n)n=(n-1)&n, ++times;
    return times;
}

/**
    有序一次旋转数组的最小值
    *******
    核心是重复元素的考虑,若输入没有重复元素,则只需@1便可以,若有则需要增加@2
    思路:把所有可能的下标更新情况都考虑,即使有重复元素, 也就多了个分类,多考虑一种情况而已
**/
#define ZCSError() {cout<<"nullptr!!"<<endl;return-1;}
int jzOffer::ti8::minZ(int* a, int l, int h){
    if(a==nullptr)ZCSError();
    if(l==h)return a[l];
    if(l>h){
        cout<<"error: low is higher than high!"<<endl;
        return -1;
    }

    int mid((l+h)/2);
    int mid1((l+h)/2), l1(l), h1(h);
    //@1
    while(mid>l){
        if(a[mid]>=a[l] && a[mid]>a[h])
            l=mid;
        else
            h=mid;
        mid=(l+h)/2;
    }
    //@2
    while(mid1>l1){
        if(a[mid1]>=a[l1] && a[mid1]>=a[h1])
            l1=mid1;
        else
            h1=mid1;
        mid1=(l1+h1)/2;
    }
    int m1=a[l]<a[h]?a[l]:a[h];
    int m2=a[l1]<a[h1]?a[l1]:a[h1];

    return m1<m2?m1:m2;
}


/**
    由二叉树的前序和中序遍历,重建二叉树的结构
**/

int jzOffer::ti6::isFind(int* a, int* b, int len){
    int idx(0);
    while(idx<len){
        if(a[0]==b[idx])
            return idx;
        else
            ++idx;
    }
    return -1;
}

jzOffer::ti6::bstNode* jzOffer::ti6::constructBst(int* preOrder, int* inOrder, int len){
    bstNode* node=nullptr;
    if(len==0 || preOrder==nullptr || inOrder==nullptr)
        return node;
    int idx=isFind(preOrder, inOrder, len);
    if(idx==-1){
        cout<<"Bad find!"<<endl;
        return node;
    }
    else{
        node=new(nothrow) bstNode;
        if(node==nullptr){
            cout<<"New error!"<<endl;
            return node;
        }
        node->val=preOrder[0];
        if(idx==0){
            node->pL=(bstNode*)nullptr;
            node->pR=constructBst(preOrder+1, inOrder+1, len-1);
        }
        else{
            node->pL=constructBst(preOrder+1, inOrder+0, idx);
            node->pR=constructBst(preOrder+idx+1, inOrder+idx+1, len-idx-1);
        }
        return node;
    }
}


/**
对同一行,同一列的元素都递增的二位数组进行查找
**/
void jzOffer::ti3::test(){
    int row(0), col(0), elem(0);
    cin>>row>>col>>elem;
    if(row<=0 || col<=0)return;

    int** arr=new int*[col];for(int i(0); i<col; ++i)arr[i]=new int[row];
    for(int i(0); i<row; ++i)for(int j(0); j<col; ++j)cin>>arr[i][j];


    if(find2DElement(arr, row, col, elem))
        cout<<"Find it!"<<endl;
    else
        cout<<"Don't find it!"<<endl;
}

bool jzOffer::ti3::find2DElement(int** arr, int row, int col, int n){
    for(int i(0), j(col-1); i<row && j>=0;)
        if(arr[i][j]==n)
            return true;
        else if (n>arr[i][j])
                ++i;
            else
                --j;
    return false;
}

/**
hash:以空间换时间
**/
char jzOffer::ti35::findFirstChar(string str){
    if(str.size()==0) return NULL;
    int arr[256]={0};
    for (int i(0); i<str.size(); ++i)arr[(int)str[i]]+=1;
    char res;
    for (int i(0); i<str.size();++i)
        if(arr[(int)str[i]]==1){
            res=str[i];
            break;
        }
    return res;
}


/**
array与数组相比,作为类模板,提供了成员函数操作高效,但大小也是编译时确定
**/
void wdBaoDian::ti257::findSmallK(){
    int nums(0), k(0);
    while(cin>>nums>>k){
        if(nums<=0);//
        if(k<=0);//
        if(k>=nums);//
        vector<int> res;
        int aNum(0);
        for(int i=0;i<k;++i)cin>>aNum, res.push_back(aNum);
        vector<int>::iterator sm;
        //nums limited,,
        while(cin>>aNum){
            sm=findMax(res);
            if(aNum<*sm)swap(*sm,aNum);
        }
        for(auto tmp:res)cout<<tmp<<endl;
    }
}

//vector<int>::iterator wdBaoDian::ti257::findMax(const vector<int>& nums){
//const引用使得返回的迭代器类型也是const,便不能拷贝给非const的迭代器,报类型mismatch
//如果是const引用,便只能调用cbegin();调用begin的话报的错是没有相关的=运算符重载,????内在实现不明?
vector<int>::iterator wdBaoDian::ti257::findMax(vector<int>& nums){
    vector<int>::iterator res=nums.begin();
    for(auto tmp=nums.begin(); tmp<nums.end(); ++tmp)if(*tmp>*res)res=tmp;
    return res;
}
