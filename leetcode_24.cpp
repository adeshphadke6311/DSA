//24. Swap Nodes in Pairs
#include<iostream>
using namespace std;


  //Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* second = first->next;

        while(first && second){
            ListNode* third = second->next;
            second->next = first;
            first->next = third;

            if(prev){
                prev->next = second;
            }else{
                head = second;
            }

            //Updation of Pointers
            prev = first;
            first = third;
            second = third ? third->next : nullptr;
        }

        return head;
        
    }
};

int main(){
    return 0;
}