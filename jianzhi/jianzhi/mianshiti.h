#ifndef MIANSHITI_H_INCLUDED
#define MIANSHITI_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <exception>
using namespace std;

namespace jzOffer{

    struct listNode{
        int val;
        listNode* pNext;
    };
    class ti13{
        public:
            void deleteNode(jzOffer::listNode** pListHead, jzOffer::listNode* pToBeDeleted);
    };

    class ti12{
        private:
            inline void addOne(char* a, int& len, bool& isCon);
        public:
            int print1ToMaxN(int n);
    };

    class ti11{
        private:
            bool equa(int a, int b);
            double curPower(double base, int exponent);
        public:
            bool isValidInput;
            double power(double base, int exponent);
    };

    class ti10{
        public:
            int numberOfOne(int n);
    };

    class ti8{
        public:
            int minZ(int* arr, int low, int high);
    };


    template<typename T>
    class ti7{
    /**
    两个栈实现队列
    queue: push, front, pop, empty, size
    stack: push, top, pop, empty, size
    **/
        public:
            void pushTail(const T& node){
                stk1.push(node);
            }

            T popHead(){
                T node;
                if(stk2.empty()){
                    while(!stk1.empty()){
                        node=stk1.top();
                        stk2.push(node);
                        stk1.pop();
                    }
                }
                if(stk2.empty())
                    throw new exception;
                node=stk2.top(), stk2.pop();
                return node;
            }
        private:
            stack<T> stk1;
            stack<T> stk2;
    };
    template<typename T>
    class ti7_{
    /**
    两个栈实现队列
    **/
        public:
            void push(const T& node){
                que1.push(node);
            }

            T topAndPop(){
                T node;
                if(que2.empty()){
                    swapQueue();
                }
                if(que2.empty())
                    throw new exception;
                node=que2.front(), que2.pop();
                return node;
            }
        private:
            void swapQueue(){
                if(que1.empty())
                    return;
                T node=que1.front();
                que1.pop();
                swapQueue();
                que2.push(node);
            }
            queue<T> que1;
            queue<T> que2;
    };

    class ti6{
        private:
            int isFind(int*, int*, int);
        public:
            struct bstNode{
                int val;
                bstNode* pL;
                bstNode* pR;
            };
            ti6::bstNode* constructBst(int* preOrder, int* inOrder, int len);
    };

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
