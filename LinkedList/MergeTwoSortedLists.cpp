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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* ptr=NULL;
        
        if(list2==NULL) return list1;        \
        if(list1==NULL) return list2;

        
        if(list2->val >= list1->val)
        {
            ptr=list1;
            list1=list1->next;
        }
        else{
            ptr=list2;
            list2=list2->next; 
        }
        
        ListNode *merger_head=ptr;
        
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val <= list2->val)            {
                ptr->next=list1;
                list1=list1->next;
                cout<<"c1_"<<ptr->val<<endl;
            }
            else{
            ptr->next=list2;
            list2=list2->next;
                cout<<"c2_"<<ptr->val<<endl;
            }
            ptr=ptr->next;
        }
        
        while(list1!=NULL)
        {
            ptr->next=list1;
            list1=list1->next;
            cout<<"c3_"<<ptr->val<<endl;
            ptr=ptr->next;
        }
        while(list2!=NULL)
        {
            ptr->next=list2;
            list2=list2->next;
            cout<<"c4_"<<ptr->val<<endl;
            ptr=ptr->next;
        }
        return merger_head;
        
    }
};