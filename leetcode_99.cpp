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
    //Time Complexity   :   O(n) Amortized
    //Space Complexity  :   O(1)
public:
    void recoverTree(TreeNode* root){
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        while(root != nullptr){

            if(root->left == nullptr){
                if(prev != nullptr && prev->val > root->val){
                    if(!first){
                        first = prev;
                    }
                    second = root;
                }
                prev = root;
                root = root->right;
            }else{
                TreeNode* IP = root->left;

                while(IP->right != nullptr && IP->right != root){
                    IP = IP->right;
                }

                if(IP->right == nullptr){
                    IP->right = root;
                    root = root->left;
                }else{
                    if(prev != nullptr && prev->val > root->val){
                        if(!first){
                            first = prev;
                        }
                        second = root;
                    }
                    prev = root;
                    IP->right = nullptr;
                    root = root->right;
                }
            }

        }

        if(first && second){
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
    /*
        Time Complexity     :   O(n)
        Space Complexity    :   O(h)
                                O(log n) For Balanced BST
                                O(n) For Skewed Tree

    
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void helper(TreeNode* root){
        if(root == nullptr) return;

        helper(root->left);

        if(prev != nullptr && prev->val > root->val){
            if(!first){
                first = prev;
            }

            second = root;
        }

        prev = root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        
    }

    */
};