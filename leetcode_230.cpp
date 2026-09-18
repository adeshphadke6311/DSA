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
    // Space Complexity : O(h)
    // O(log n) for balanced BST
    // O(n) for skewed BST
public:
    int prevOrder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root->left){
            int left_ans = kthSmallest(root->left, k);
            if(left_ans != -1) return left_ans;
        }

        if(prevOrder + 1 == k) return root->val;

        prevOrder += 1;

        if(root->right){
            int right_ans = kthSmallest(root->right, k);
            if(right_ans != -1) return right_ans;
        }

        return -1;
        
    }
};