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
    ListNode* merge(ListNode* root1,ListNode* root2)
    {
        if(root1==nullptr)  return root2;
        else if(root2==nullptr)  return root1;
        ListNode* node1=root1;
        ListNode* node2=root2;
        ListNode* head1 = new ListNode(0);
        ListNode* temp = head1;
        while(node1 && node2)
        {
            if(node1->val<=node2->val)
            {
                temp->next = node1;
                node1=node1->next;
                temp = temp->next;
            }else
            {
                temp->next = node2;
                node2=node2->next;
                temp = temp->next;
            }
        }
        if(node1)   temp->next = node1;
        else if(node2)  temp->next = node2;
        return head1->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
        return nullptr;
        }
        while(lists.size()>1)
        {
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
};