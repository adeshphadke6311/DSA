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
    // Time Complexity   : O(n)
    // Space Complexity  : O(h), where h is tree height
    //                    O(log n) for balanced tree
    //                    O(n) for skewed tree
public:
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == nullptr) return true;

        if(min != nullptr && root->val <= min->val) return false;
        if(max != nullptr && root->val >= max->val) return false;

        return helper(root->left, min, root) &&
                helper(root->right, root, max);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
        
    }

};