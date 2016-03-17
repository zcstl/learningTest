#include <iostream>
#include <SingleName.h>
#include <vector>
#include <memory.h>

using namespace std;

int main()
{
    /*
    int* parentVal=(int*)malloc(2*sizeof(int));
    memset(parentVal,0,2*sizeof(int));
    parentVal[0]=1;
    parentVal[1]=2;
    cout<<parentVal[0]<<endl;
    cout<<parentVal[1]<<endl;
    */
    int a[]={2,3,4,1,5,6,8,11};
    zcs::sortZCS::quickSort(a, 8);
    for (int i=0;i<8;++i)
        cout<<a[i]<<endl;
}
