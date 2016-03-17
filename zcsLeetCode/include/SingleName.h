
#ifndef SINGLENAME_H
#define SINGLENAME_H
#include <vector>
#include <iostream>

//using namespace std;
namespace zcs{
    class sortZCS
    {
        public:
        static void quickSort(int* nums,unsigned int n);
        private:
        static void recurSort(int* nums,int* start,int* end1);
        static int* getSu(int* nums,int* start,int* end1);
        inline static int* sortBySu(int* nums,int* start,int* end1, int* su);
    };


    class SingleName
    {
        public:
            //SingleName(){};
            //virtual ~SingleName(){};
            int singleNumber(std::vector<int>&);
        protected:
        private:
    };

    class NimGame
    {
        public:
            bool canWinNim(int);
    };

    class Leet238
    {
        public:
            std::vector<int> productExceptSelf(std::vector<int>&);
    };

    struct Leet153
    {
        int findMin(std::vector<int>&);
    };

    class Leet337
    {
        private:
            struct TreeNode
            {
                int val;
                TreeNode *left;
                TreeNode *right;
                TreeNode(int x) : val(x), left(NULL), right(NULL) {}
            };

            //
            int dynamicPro(int*,int);

            //
            int* getMaxVal(TreeNode*);
            /**
            int parentVal[2]={0,0};
            int leftVal[2]={0,0};
            int rightVal[2]={0,0};
            int* tmpValPtr;  该指针也许在递归中被共用不会出错,但这种精细不是个好习惯或没有必要,容易出错
            原以这种成员变量保存递归数据,但递归时发生相互覆盖,故还是堆中存放
            **/

        public:
            int robNote(TreeNode*);
            int rob(TreeNode*);

    };
}
#endif // SINGLENAME_H
