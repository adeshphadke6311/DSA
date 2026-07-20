
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
    //Space Complexity  :   O(1)
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool hasCycle = false;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                hasCycle = true;
                break;
            }

        }

        if(!hasCycle){
            return nullptr;
        }

        slow = head;

        //ListNode* prev = nullptr;
        while(slow != fast){
            slow = slow->next;
            //prev = fast;
            fast = fast->next;
        }

        //prev->next = nullptr; //It will eliminate cycle in the linked list

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

    //tail->next = head->next->next;  //To form a cycle


    Solution sol;

    ListNode* cycleBeginNode;

    cycleBeginNode = sol.detectCycle(head);
    
    if(cycleBeginNode != nullptr){
        cout<<"Cycle begins from "<<cycleBeginNode->val<<endl;
    }else{
        cout<<"No cycle exists"<<endl;
    }


    return 0;
}