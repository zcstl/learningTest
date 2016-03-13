#include <iostream>
#include <SingleName.h>
#include <vector>
#include <memory.h>

using namespace std;

int main()
{
    int* parentVal=(int*)malloc(2*sizeof(int));
    memset(parentVal,0,2*sizeof(int));
    parentVal[0]=1;
    parentVal[1]=2;
    cout<<parentVal[0]<<endl;
    cout<<parentVal[1]<<endl;

}
