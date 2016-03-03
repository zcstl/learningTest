#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{

    vector<string> vec1={"123"};
    char vec2[4]={'1','2','3','\0'};
    const char* vec3="123";
    cout << equal(vec1.cbegin(),vec1.cend(), vec2) << endl;
    cout << equal(vec1.cbegin(),vec1.cend(), vec3) << endl;
    free(vec1);
    free(vec2);
    free(vec3);
    return 0;
}
