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
    //Space Complexity  :   O(log n) for balanced BST
public:
    TreeNode* prev = nullptr;
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        if(root->left){
            int left_min = minDiffInBST(root->left);
            ans = min(ans, left_min);

        }

        if(prev){
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        if(root->right){
            int right_min = minDiffInBST(root->right);
            ans = min(ans, right_min);
        }
        return ans;

        
    }
};