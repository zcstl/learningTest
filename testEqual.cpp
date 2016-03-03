#include <stdlib>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    char* p[] = { "Hello", "World", "!" };
    char* q0 = _strdup(p[0]);
    char* q1 = _strdup(p[1]);
    char* q2 = _strdup(p[2]);
    char* q[] = { q0, q1, q2 };
    char* r[] = { p[0], p[1], p[2] };
    cout << equal(begin(p), end(p), q) << endl;
    cout << equal(begin(p), end(p), r) << endl;
    free(q0);
    free(q1);
    free(q2);
    return 0;
}
