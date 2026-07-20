
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x),next(next) {}



};

class Solution {
    //Time Complexity   :   O(n)
    //Sapce Complexity  :   O(1)
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }

        return false;
        
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

    //tail->next = head->next->next;  //To form a cycle


    Solution sol;

    if(sol.hasCycle(head)){
        cout<<"This LinkedList has Cycle"<<endl;
    }else{
        cout<<"No cycle exists"<<endl;
    }


    return 0;
}