//138. Copy Linked List with Random Pointer

#include<iostream>
#include<unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
    /*
    Time Complexity     :   O(n)
    Space Complexity    :   O(n)

    */
public:
    Node* copyRandomList(Node* head) {
        /*

        if(head == nullptr){
            return nullptr;
        }
        unordered_map<Node*, Node*> m;

        Node* newHead = new Node(head->val);
        m[head] = newHead;
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        while(oldTemp != nullptr){
            Node* newNode = new Node(oldTemp->val);
            m[oldTemp] = newNode;
            newTemp->next = newNode;
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        newTemp = newHead; oldTemp = head;

        while(oldTemp != nullptr){
            newTemp->random = m[oldTemp->random];
            newTemp = newTemp->next; oldTemp = oldTemp->next;
        }

        return newHead;
        */



        // Time Complexity  :   O(n)
        // Space Complexity :   O(1)
        if(head == nullptr){
            return nullptr;
        }

        //Make the copy of node after original node
        //A -> A' -> B -> B' -> C -> C'

        Node* curr = head;

        while(curr){
            Node* copyNode = new Node(curr->val);
            copyNode->next = curr->next;
            curr->next = copyNode;
            curr = copyNode->next;
        }

        //A.random = C then A' = C', curr->next->random = current.random->next
        //Copying Random Pointers

        curr = head;

        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        //Separating original and copied list

        curr  = head;
        Node* newHead = head->next;

        while(curr){
            Node* copy = curr->next;
            curr->next = copy->next;
            
            if(copy->next){
                copy->next = copy->next->next;
            }
            
            curr = curr->next;
            
        }

        return newHead;

        



        
    }
};