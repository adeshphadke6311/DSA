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