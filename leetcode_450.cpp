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


TreeNode* getInorderSuccessor(TreeNode* root){
    while(root != nullptr && root->left != nullptr){
        root = root->left;
    }
    return root;
}
class Solution {
    /*
    Time Complexity   :   O(h) h - Height of Tree
                          O(log n) For Balanced BST
                          O(n) For skewed Tree
    
    Space Complexity    : O(h) h - Height of Tree - Due to recursion 
                          O(log n) For Balanced BST
                          O(n) For skewed Tree

    */
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }else{
            //key = root->val

            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else{
                //We have to find inorder successor
                TreeNode* IS = getInorderSuccessor(root->right);
                //Inorder successor is the leftmost node in right subtree

                root->val = IS->val;
                root->right = deleteNode(root->right, IS->val);
            }
        }

        return root;
        
    }

};