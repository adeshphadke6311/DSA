#include <iostream>
#include <queue>
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
    //Space Complexity  :   O(w) w = Maximum width of Tree
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth =1;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                //First Leaf node that will give minimum Depth
                if(curr->left == nullptr && curr->right == nullptr){
                    return depth;
                }

                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);

                
            }
            depth++;
        }
        
        return depth;
    /*
        //Time Complexity   :   O(n)
        //Space Complexity  :   O(h) h = Height of Binary Tree
        if(root == nullptr) return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if(root->left == nullptr) return rightDepth+1;
        if(root->right == nullptr) return leftDepth+1;
        return min(leftDepth, rightDepth)+1;
    */


        
    }
};