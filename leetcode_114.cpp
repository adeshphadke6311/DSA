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
    //                      O(log n) For balanced Binary Tree
    //                      O(n) For Skewed Tree
public:
    TreeNode* lastVisited = nullptr;
    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        flatten(root->right);
        flatten(root->left);

        root->left = nullptr;
        root->right = lastVisited;
        lastVisited = root;
        
    }
};