#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    //Time Complexity   :   O(n)
    // Space Complexity : O(h), where h is height of tree
    // Worst Case        : O(n) for a skewed tree
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        if(root == p || root == q){
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA && rightLCA){
            return root;
        }else if(leftLCA){
            return leftLCA;
        }else{
            return rightLCA;
        }
    }
};