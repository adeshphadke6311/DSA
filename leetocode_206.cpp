//206. Reverse a Linked list

#include <iostream>
using namespace std;

struct ListNode{

    int val;
    ListNode* next;

    ListNode(){
        val = 0;
        next = nullptr; //Always use nullptr because it can't be treated as 0, NULL is internally treated as integer 0;

    }

    ListNode(int x){
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* next){
        val = x;
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

    void print(ListNode* head){

        while(head != nullptr){
            cout<<head->val<<" ";
            head = head->next;

        }
        cout<<endl;
    }
};

int main(){

    int input_nodes;
    cout<<"Enter Number of Nodes : ";
    cin>>input_nodes;
    cout<<endl;

    cout<<"Enter Nodes "<<endl;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i=0; i<input_nodes; i++){
        int j;
        cin>>j;

        ListNode* newNode = new ListNode(j);

        if(head == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Solution sol;
    head = sol.reverseList(head);
    sol.print(head);
    return 0;
}