/**
    1.list是双向链表(循环),最适合此情景
    list的迭代器不支持加减运算,只支持++或--,
    1.1. if(iter==nums.end())++iter;循环遍历时留意end迭代器
    1.2. list<T>::erase()函数删除迭代器指向元素,返回下一个迭代器,注意与vector的区别
    1.2.1 vector<T>::erase(iter)返回值与iter相同,但还是用iter接受较好,与list一致
    1.3. list的push_back, erase, size等比较常用
    vector的erase开销大
    2.set与map底层都是红黑树， set不保留重复值，有去重和排序（增序）效果。
**/


#include <iostream>
#include <list>
//#include <vector>

using namespace std;
/*
int main(){
    int N(0);
    vector<int> nums;
    while(cin>>N){
        nums.clear();
        for(int i=0;i<N;++i)nums.push_back(i);
        auto biginIter=nums.begin();
        for(int idx=0, sizet=nums.size(); sizet>1;){
            idx=(idx+2)%sizet;
            nums.erase(biginIter+idx);
            --sizet;
        }
        cout<<*nums.begin()<<endl;
    }


}*/


int main111(){
    int N(0);
    list<int> nums;
    while(cin>>N){
        nums.clear();
        for(int i=0;i<N;++i)nums.push_back(i);
        auto iter=nums.begin();
        for(int sizet=nums.size(); sizet>1; --sizet)
            //nums.erase(biginIter+(++(++idx))); biginIter指针已经不知所踪,,,
            //cout<<*iter<<endl,cout<<*nums.erase(++(++iter))<<endl,cout<<*iter<<endl;
        {
            if(++iter==nums.end())
                ++iter;
            if(++iter==nums.end())
                ++iter;
            iter=nums.erase(iter);
            if(iter==nums.end())
                ++iter;
        }
        cout<<*nums.begin()<<endl;
    }
}



/**
    set和map的底层都是红黑树,故元素顺序与存储顺序不同
    题目:输入一个字符串，求出该字符串包含的字符集合
    该实现比较low,使用vector存入数据时查找是否存在再pus
    比较好的思路:将输入存储到一个数组里,在简要的定义一个char [256]数组,对char做哈希统计次数,然后再遍历原数组,
        输出并将哈希空间对应值置为-1(标志位),space要求O(n),时间复杂度较好.
**/
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


/**
    数独问题,可采用暴力解法,比较花时间写,,,
**/

/*
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
    int nums[9][9]={0};
    while(cin>>nums[0][0]){  //不能用while(1),oj系统不支持,,,,
        for(int i(1); i<9; ++i)cin>>nums[0][i];
        for(int i(1); i<9; ++i){
            //while(cin>>nums); //低级错误,想想nums是什么类型,,,
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
            for(int j(0); j<9; ++j) //把9写成0调试了n久,,,,,
                cout<<nums[i][j];
            cout<<endl;
        }
    }


}

*/
