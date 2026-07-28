#include<iostream>
using namespace std;
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n/k)
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //Check if k node exists
        int count = 0;
        ListNode* temp = head;

        while(count < k){
            if(!temp){
                return head;
            }
            temp = temp->next;
            count++;
        }
        
        //Recursively call for remaining linked list
        ListNode* newHead = reverseKGroup(temp, k);

        //Reverse Current Group
        temp = head;
        count = 0;
        
        while(count<k){
            ListNode* next = temp->next;
            temp->next = newHead;
            newHead = temp;
            temp = next;
            count++;
        }
        return newHead;
    }
};

int main(){
    return 0;
}