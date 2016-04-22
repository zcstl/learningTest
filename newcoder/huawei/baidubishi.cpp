/**
    若虚拟内存管理系统采用FIFO的方式缓存，输入一个缓存大小，和一个页面编号请求数组及大小，
    输出其cache miss数目，注意编号大小为[1 50]

    思路：
    使用stl的queue实现FIFO，(哈希)使用一个char数组保存 页面是否在缓存中，使得查找为O(1)

    小结：这题思路很明细，暴力的遍历，但页面范围信息没有使用，要用到此信息，自然联想到哈希
**/
/*
#include <queue>
#include <stdio.h>
#include <memory.h>
#define QUEUE_SIZE 3
#define Memset(arr, val) memset(arr, val, sizeof(arr))
using namespace std;
int countCacheMiss(int cS, int* pR, int n){
    if(pR==nullptr || cS<1 || n<1)
        return -1;
    queue<char> cache;
    char has[50];
    Memset(has,0);
    int miss(0), hasSize(0);
    for(int i(0); i<n; ++i)
        if(!has[pR[i]])
            if(hasSize<cS)
                ++miss, has[pR[i]]=1, ++hasSize, cache.push(pR[i]);
            else
                ++miss, has[cache.front()]=0, cache.pop(), cache.push(pR[i]), has[pR[i]]=1;
    return miss;
}
void test1(){
    int a[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0};
    printf("%d\n",countCacheMiss(3, a, 16));
}
void test2(){
    int a[]={2,3,1,3,2,1,4,3,2};
    printf("%d\n",countCacheMiss(2, a, 9));
}
int main(){
    test1();
    test2();
}
*/
/**
    SJF调度策略,输入一个请求时间([0 100))数组和作业持续时间((0 100))数组,且按请求时间升序
    求出平均等待时间
**/
/*
#include <iostream>
using namespace std;
float waitingTimeSJF(int* rT, int* dur, int len){
    int* res=new int[len];
    for(int i(0); i<len; ++i)res[i]=0;
    int T=0;
    int waitSelected(0);
    int flag=100;
    for(int i(0); i<len; ++i){
        if(rT[i]>=T){
            while(rT[i]!=T)++T;
            res[i]=T;
            T+=dur[i];
            continue;
        }
        for(int j(0); j<len; ++j){
            if(rT[j]<T && res[j]==0)
                if(dur[j]<flag)
                    flag=dur[j], waitSelected=j;
        }
        res[waitSelected]=T;
        T+=dur[waitSelected];
        flag=100;
    }
    int total(0);
    for(int i(0); i<len; ++i)
        total+=res[i]-rT[i];
    delete []res;
    return total*1.0/(len*1.0);
}

int main(){
    int a[]={0,1,3,9};
    int b[]={2,1,7,4};
    cout<<waitingTimeSJF(a, b, 4)<<endl;
}*/
