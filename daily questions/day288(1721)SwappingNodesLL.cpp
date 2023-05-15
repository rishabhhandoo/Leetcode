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
    ListNode* swapNodes(ListNode* head, int k) {
        int num =0;
        ListNode* temp = head;
        while(temp)
        {
            num++;
            temp = temp->next;
        }
        temp = head;
        int i=0;
        int l = 0;
        int r = 0;
        while(temp)
        {
            i++;
            if(i==k)
            {
                l=temp->val;
            }
            if(i==num-k+1)
            {
                r= temp->val;
            }
            temp = temp->next;
        }
        i=0;
        temp=head;
        while(temp)
        {
            i++;
            if(i==k)
            {
                temp->val = r;
            }
            if(i==num-k+1)
            {
                temp->val=l;
            }
            temp = temp->next;
        }
        
        return head;


    }
};