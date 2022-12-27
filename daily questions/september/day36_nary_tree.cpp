/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(!root)   return ans;
        vector<int> first;
        first.push_back(root->val);
        ans.push_back(first);
        
        while(!q.empty())
        {
            cout<<1<<" "<<endl;
            int lvl = q.size();
            vector<int> temp;
            bool flag=true;

            while(lvl--)
            {
                cout<<2<<" "<<endl;
                Node* curr = q.front();
                q.pop();
                for(int i=0 ; i<curr->children.size();i++)
                {
                    Node* abhi = curr->children[i];
                    cout<<"hmm"<<endl;
                    q.push(abhi);
                    temp.push_back(abhi->val);
                    flag = false;

                }
                
            }
            if(!flag)
                ans.push_back(temp);
        }
        return ans;
    }
};