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
        //Recursive Approach
        /*

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

        */


        //Iterative Approach
        //Time Complexity   :   O(n)
        //Space Complexity  :   O(1)
        
        if(!head || k == 1){
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;

        while(true){
            //Find the kth node from prevGroup
            ListNode* kth = prevGroup;

            for(int i=0; i<k && kth; i++){
                kth = kth->next;
            }

            if(!kth){
                break;
            }

            //Reverse current Group

            ListNode* groupNext = kth->next;
            ListNode*prev = groupNext;
            ListNode* curr = prevGroup->next;

            while(curr != groupNext){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            //Connect reverse group

            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;

        }
        return dummy.next;
    }
};