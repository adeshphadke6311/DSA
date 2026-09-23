#include <iostream>
#include <queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(m) m - Maximum width of tree
public:
    Node* connect(Node* root) {
        if(root == nullptr || root->left == nullptr){
            return root;
        }

        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        Node* prev = nullptr;

        while(q.size()){
            Node* curr = q.front();
            q.pop();

            if(!curr){
                if(q.empty()){
                    break;
                }
                prev = nullptr;
                q.push(nullptr);
            }else{
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }

                if(prev){
                    prev->next = curr;
                }
                prev = curr;
            }

        }

        return root;


        
    }
};

int main(){
    return 0;
}