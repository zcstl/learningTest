#ifndef MIANSHITI_H_INCLUDED
#define MIANSHITI_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace jzOffer{
    class ti3{
        public:
            void test();
            bool find2DElement(int**, int, int, int);
    };
    class ti35{
        public:
            //char findFirstChar(char* str, unsigned int len);
            //c_str没有string好用
            char findFirstChar(string str);

    };


}

namespace wdBaoDian{
    class ti257{
        public:
            void findSmallK();
        private:
            vector<int>::iterator findMax(vector<int>&);
    };
}


#endif // MIANSHITI_H_INCLUDED
