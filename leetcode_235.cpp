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
    /*
        Time Complexity :   O(h)
                            O(log n) For Balanced BST
                            O(n) For Skewed Tree
        Space Complexity :  O(1)
    
    */
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root){
            if(p->val < root->val && q->val < root->val){
                root = root->left;
            }else if(p->val > root->val && q->val > root->val){
                root = root->right;
            }else{
                return root;
            }
        }
        return nullptr;

        /*
        Time Complexity   :     O(h)
                                O(log n) For Balanced BST
                                O(n) For Skewed Tree
        Space Complexity  :     O(h)
                                O(log n) For Balanced BST
                                O(n) For skewed Tree

        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }else{
            return root;
        }
        */
        
    }
};