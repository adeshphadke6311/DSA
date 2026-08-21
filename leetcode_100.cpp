#include <iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(h) h = Height of Tree
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
        if(p == nullptr && q == nullptr) return true;
        if((p==nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
        */

        if(p == nullptr || q == nullptr){
            return p == q;
        }

        if(p->val != q-> val) return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left && right;
    }
};