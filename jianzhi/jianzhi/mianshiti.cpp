#include "mianshiti.h"
#include <array>
#include <vector>
#include <memory.h>

/**
    删除链表倒数第k个节点
**/
jzOffer::listNode* jzOffer::ti15::getTheLastKthNode(jzOffer::listNode** pList, int k){


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
