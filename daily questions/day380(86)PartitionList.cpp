/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        ListNode* prev ;
        while(curr && curr->val < x)
        {
            prev=curr;
            curr=curr->next;
        }

        ListNode* temp=curr;
        ListNode* temp_prev=prev;
        while(temp)
        {
            if(temp->val<x)
            {
                ListNode* ahead = temp->next;
                temp->next = curr;
                if(temp_prev!=nullptr)
                    temp_prev->next = ahead;
                if(prev!=nullptr)
                    prev->next=temp;
                else    head=temp;
                prev=temp;
                temp=ahead;
            }else{
                temp_prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};