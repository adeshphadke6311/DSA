#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(m) m = Number of Nodes having child
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return head;

        Node* curr = head;

        while(curr){
            //Valid Child
            if(curr->child){
                //Flatten list

                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;


                //Find a tail node

                while(curr->next){
                    curr = curr->next;
                }

                //Attach child tail to next

                if(next != nullptr){
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }


        return head;


        
    }
};

int main(){
    return 0;

}