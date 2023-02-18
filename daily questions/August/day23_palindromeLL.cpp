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
    int length(ListNode* temp)
    {
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int len = length(temp);
        
        
        stack<int> s;
        queue<int> q;
        int mid=len>>1;
        cout<<" the value of mid is -> "<<mid<<endl;
        for(int i=1;i<=len;i++)
        {
            if(len&1){
                if(i<=mid)  s.push(temp->val);
                if(i>mid+1) q.push(temp->val);    
            }else{
                if(i<=mid)  s.push(temp->val);
                if(i>mid) q.push(temp->val); 
            }
        temp=temp->next;
        }
        cout<<s.size()<<" this is the size of stack "<<endl;
        cout<<q.size()<<" this is the size of queue "<<endl;
        while(!s.empty()){
            if(s.top()==q.front()){
                s.pop();
                q.pop();
            }
            else return false;
        }
        return true;
        
        
        
    }
};