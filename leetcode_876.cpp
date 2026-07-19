
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : next(next) {}



};

class Solution{
    public:

    ListNode* middleNode(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main(){

    cout<<"Enter number of Nodes ";
    int n;
    cin>>n;
    cout<<endl;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout<<"Enter Nodes"<<endl;

    for(int i=0; i<n; i++){
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

    ListNode* middle = sol.middleNode(head);
    cout<<"Middle Node of Linked List = "<<middle->val<<endl;


    return 0;
}