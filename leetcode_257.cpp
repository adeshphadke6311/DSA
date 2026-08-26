#include <iostream>
#include <vector>
#include <string>
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
    // Time Complexity      : O(n)
    // Auxiliary Space      : O(h)
    // Output Space         : O(L * h)
    // Overall Space        : O(h + L * h)
public:
    void helper(TreeNode* root, string path, vector<string>&ans){ //O(n)
        if(!root->left && !root->right){
            ans.push_back(path);
            return;
        }

        if(root->left){
            helper(root->left, path+"->"+to_string(root->left->val), ans);
        }

        if(root->right){
            helper(root->right, path+"->"+to_string(root->right->val), ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = to_string(root->val);
        vector<string> ans;

        helper(root, path, ans);
        return ans;
    }
};