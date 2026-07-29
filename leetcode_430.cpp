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
    
    /* 
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
    */

    //Time Complexity   :   O(n)
    //Space Complexity  :   O(m) m = Maximum nesting depth
private:
    Node* findTail(Node* head){
        Node* tail = head;

        while(head){
            tail = head;
            //Valid child

            if(head->child){
                Node* nextNode = head->next;
                Node* childHead = head->child;

                Node* childTail = findTail(childHead);
                head->next = childHead;
                childHead->prev = head;
                head->child = nullptr;

                // Attach tail
                if(nextNode){
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }
                tail = childTail;

            }
            head = tail->next;
        }
        return tail;

    }
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return head;

        findTail(head);

        return head;

        
    }
};

int main(){
    return 0;

}