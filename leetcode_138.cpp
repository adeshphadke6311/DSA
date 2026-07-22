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


        
    }
};