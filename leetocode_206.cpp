//206. Reverse a Linked list

#include <iostream>
using namespace std;

struct ListNode{

    int val;
    ListNode* next;

    ListNode(){
        val = 0;
        next = nullptr;

    }

    ListNode(int x){
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* next){
        this->next = next;
    }
};


class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n)
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
        
    }
};

int main(){

    int input_nodes;
    cout<<"Enter Number of Nodes : ";
    cin>>input_nodes;
    cout<<endl;

    cout<<"Enter Nodes ";

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int j;
    for(int i=0; i<input_nodes; i++){
        cin>>j;

        ListNode* newNode = new ListNode(j);

        if(head == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return 0;
}