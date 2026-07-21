
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
    //Time Complexity   :   O(m + n)
    //Space Complexity  :   O(m + n)
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr || list2 == nullptr){
            return list1 == nullptr ? list2 : list1;
        }
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
        
        
    }
    ListNode* create(){
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

        return head;
    
    }

    void print(ListNode* head){
        while(head != nullptr){
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
    }
};



int main(){


    


    Solution sol;

    ListNode* head1 = sol.create();
    ListNode* head2 = sol.create();

    ListNode* head = sol.mergeTwoLists(head1, head2);

    sol.print(head);

    

    


    return 0;
}