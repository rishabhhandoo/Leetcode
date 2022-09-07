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
    void helper(string &ans,TreeNode* root)
    {
        if(!root->left && !root->right)
        { 
            ans+= to_string(root->val);
            return; 
        }
        
//         if(root->val<0)
//         {
//             ans+='-';
//             ans+= -(root->val) + '0';
//         }else
//             ans += (root->val )+ '0';

        ans+= to_string(root->val);
        
        if(root->left)
        {
            ans +='(';
            helper(ans,root->left);
            ans +=')';
        }
        if(root->right)
        {
            if(!root->left)
            {
                ans+= "()";
            }
            ans +='(';
            helper(ans,root->right);
            ans +=')';
            
        }
        return;
        
    }
    
    
    string tree2str(TreeNode* root) {
        string ans="";
        
        helper(ans,root);
        return ans;
    }
};