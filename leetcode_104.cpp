#include <iostream>
using namespace std;

// Definition for a binary tree node.
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

    /*
        Depth of a node → distance from root to that node.
        Height of a node → distance from that node to its deepest leaf.
        Height of the tree → height of the root.
    */
   
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
        
    }
};

