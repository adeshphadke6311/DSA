#include <iostream>
#include <vector>
using namespace std;

//Definition for binary tree node

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){} 
};

class Solution {
    // Time Complexity  : O(n)
    // Space Complexity : O(log n) - Recursion Stack

public:

    TreeNode* helper(vector<int>& nums, int st, int end) {

        // No elements available
        if(st > end)
            return nullptr;

        // Find middle element
        int mid = st + (end - st) / 2;

        // Middle element becomes root
        TreeNode* root = new TreeNode(nums[mid]);

        // Build left subtree
        root->left = helper(nums, st, mid - 1);

        // Build right subtree
        root->right = helper(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};