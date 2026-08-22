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
    //Time Complexity   :   o(n)
    //Space Complexity  :   O(h) h - Height of Binary Tree
public:
    int ans = 0; 
    int heightOfBinaryTree(TreeNode* root){ //O(n)
        if(root == nullptr) return 0;

        int leftHeight = heightOfBinaryTree(root->left);
        int rightHeight = heightOfBinaryTree(root->right);

        ans = max(leftHeight + rightHeight, ans);

        return max(leftHeight, rightHeight) + 1;
    }
    
    //O(1)
    int diameterOfBinaryTree(TreeNode* root) {
        heightOfBinaryTree(root); // We don't care about what height returns

        return ans;
    }




    /*
    
    int heightOfBinaryTree(TreeNode* root){ //O(n)
        if(root == nullptr) return 0;
 
        int leftHeight = heightOfBinaryTree(root->left);
        int rightHeight = heightOfBinaryTree(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
    
    //Time Complexity   :   O(n^2)
    //Space Complexity  :   O(h)
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
 
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int rootDiameter = heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right);
 
        return max(rootDiameter, max(leftDiameter, rightDiameter));
        
    }
    */

};