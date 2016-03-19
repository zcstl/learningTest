#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;



int main4()
{
    char a[2][2][3]={{{'1','2','3'},{4,5,6}},{{7,8,9},{10,11,12}}};
    //cout<<++a<<endl;
    for(int i=0;i<12;++i)
        cout<<a[i/6][i/3%2][i%3]<<endl;
}



