#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

inline int selectMax(int* nums, int par1, int par2)
{
    int sta=par1-1;
    int ed=par2-1;
    int max(0);
    for(int i=sta;i<=ed;++i)
    {
        max=nums[i]>max?nums[i]:max;
    }
    return max;
}

inline void updateMan(int* nums, int par1, int par2)
{
    int pos=par1-1;
    int val=par2;
	nums[pos]=val;
}

int main1() //main()等效于int main(), 没有void main!!!
{
    //N  M
    int N(0), M(0);
    cin>>N;  //cin
    if ((N<=0)||(N>30000))
    {
        cout<<"Bad N"<<endl;
        return 1;
    }
    cin>>M;
    if ((M<=0)||(M>=5000))
    {
        cout<<"Bad M"<<endl;
        return 1; //exit()声明在C的头文件stdlib.h中,或C++的cstdlib中, exit(1)相当于return 1
    }               //exit是系统调用函数,通常返回特定值,调用exit将结束P
                    //return是关键字, 结束函数调用并返回值
                    //main中return 0表示程序正确结束, return其它值通常表示错误类型

    int nums[N]; //init
    for(int count=0;count<N;++count)
    {
        cin>>nums[count];
    }

    //
    string manu;
    //char manu[2]; //使用char数组接受cin的Q, printf的结果为Q,但与"Q"比较返回0
                    //char*传给cin,首先容易越界,其次与"Q"的比较结果不正确
                    //多用string(很复杂的类型), 不要与char* 混用, 除非搞懂相关实现
    int par1(0), par2(0);
    for(int count=0;count<M;++count)
    {
        cin>>manu;
        cin>>par1;
        cin>>par2;
        //cout<<manu<<endl;
        if (manu=="Q")
        {
            if((par1<1)||(par1>N)||(par2<1)||(par2>N))
            {
                cout<<"Bad query!"<<endl;
                return 1;
            }
            if (par1>par2)
            {
                int tmp=par2;
                par2=par1;
                par1=tmp;
            }

            int maxOne=selectMax(nums, par1, par2);
            //cout<<max<<endl;
            printf("%d\n",maxOne);
            continue;
        }
        if (manu=="U")
        {
            if((par1<1)||(par1>N)||(par2<0))
            {
                cout<<"Bad update!"<<endl;
                return 1;
            }
            updateMan(nums, par1, par2);
            continue;
        }
        cout<<"Bad manu!!"<<endl;
        return 0;
    }
}
