/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        //we doing bfs
        vector<double>ans;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        
        double val = (double)root->val / level;
        ans.push_back(val);
        
        while(!q.empty())
        {
            int sz = q.size();
            int div = 0;
            double sum=0;
            bool check=false;
            while(sz--)
            {
                TreeNode* node = q.front();
                q.pop(); 
                if(node->left){
                    q.push(node->left);
                    sum+=node->left->val;
                    div++;
                    check=true;
                } 
                if(node->right){
                    q.push(node->right);
                    sum+=node->right->val;
                    div++;
                                        check=true;

                }
            }
            if(check)
            {
            val = sum/div;
            ans.push_back(val);
                
            }
                
        }
        
        return ans;
        
    }
};