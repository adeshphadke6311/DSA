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
    // Space Complexity  : O(h)
    //                     O(log n) for a balanced tree
    //                     O(n) for a skewed tree
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
       
        if(root == nullptr) return false;

        targetSum -= root->val;

        if(root->left == nullptr && root->right == nullptr){
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) || 
               hasPathSum(root->right, targetSum);


        
    }
};