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
    ListNode* reverse_list(ListNode* head1)
    {
        ListNode* prev=NULL;
        ListNode* curr=head1;
        ListNode* next;

        while(next)
        {
            next = curr->next;
            curr->next= prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head1 = reverse_list(l1);
        ListNode* head2 = reverse_list(l2);
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        int carry=0;
        while(head1 && head2)
        {
            int val = head1->val + head2->val;
            head1=head1->next;
            head2=head2->next;
            if(carry)
            {
                val+=carry;
                carry=0;
            }
            ListNode* node = new ListNode(val%10);
            temp->next = node;
            temp=temp->next;
            if(val>=10) carry=val/10;
        }
        while(head1)
        {
            int val = head1->val ;
            head1=head1->next;  
            if(carry)
            {
                val+=carry;
                carry=0;
            }
            ListNode* node = new ListNode(val%10);
            temp->next = node;
            temp=temp->next;
            if(val>=10) carry=val/10;
        }
        while(head2)
        {
            int val = head2->val ;
            head2=head2->next;
            if(carry)
            {
                val+=carry;
                carry=0;
            }
            ListNode* node = new ListNode(val%10);
            temp->next = node;
            temp=temp->next;
            if(val>=10) carry=val/10;
        }
        if (carry)
        {
            ListNode* node = new ListNode(carry);
            temp->next = node;
            temp=temp->next;
        }
        ListNode* ans = reverse_list(head->next);
        return ans;
    }
};
//basic overview
//1st reverse the ll
//2nd strt adding 
//reverse the linked list 