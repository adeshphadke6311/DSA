#include <iostream>
#include <vector>
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
    // Time Complexity   : O(n) Amortized
    // Auxiliary Space   : O(1)
    // Output Space      : O(n)
    // Total Space       : O(n)
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while(curr != nullptr){
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                //Find Inorder Predecessor
                TreeNode* IP = curr->left;
                while(IP->right != nullptr && IP->right != curr){
                    IP = IP->right;
                }

                //Create Thread between IP and Curr

                if(IP->right == nullptr){
                    IP->right = curr;
                    curr = curr->left;
                }else{
                    IP->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }

        }
        return ans;
        
    }
};