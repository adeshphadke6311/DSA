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
    //Time Complexity   :   O(n*m) n - Nodes count in tree, m = Nodes count in subree
    //Space Complexity  :   O(h) Height of Tree 
public:
    bool isIdentical(TreeNode* p, TreeNode* q){
        if(p == nullptr || q == nullptr) return p == q;

        return p->val == q->val && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;

        if(root->val == subRoot->val && isIdentical(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};