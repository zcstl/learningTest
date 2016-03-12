
#ifndef SINGLENAME_H
#define SINGLENAME_H
#include <vector>
#include <iostream>

//using namespace std;
namespace zcs{
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
        public:
            int rob(TreeNode*);

    };
}
#endif // SINGLENAME_H
