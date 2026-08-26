#include <iostream>
#include <vector>
#include <unordered_map>
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
        // Time Complexity   : O(n) average, O(n^2) Worst case [Due to hash collision]
        // Space Complexity  : O(n)
        //                      O(n) due to unordered_map
        //                      O(h) recursion stack
public:
    /*
    int search(vector<int>& inorder, int left, int right, int val){ //O(n)
        for(int i=left; i<=right; i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1; //This line will never execute
    }
    //O(n)

    */

  

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preIdx, int left, int right, unordered_map<int,int>&mp){
        if(left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx]);
        
        int inIdx = mp[preorder[preIdx]];
        preIdx++;
        root->left = helper(preorder, inorder, preIdx, left, inIdx-1, mp);
        root->right = helper(preorder, inorder, preIdx, inIdx+1, right, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return helper(preorder, inorder, preIdx, 0, inorder.size()-1,mp);
        
    }
};