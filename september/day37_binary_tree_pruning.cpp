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
    TreeNode* pruneTree(TreeNode* root) {
        // if(!root)   return root;
    
        helper(root);
        
        return root;
        
    }
    
    bool helper(TreeNode* &root)
    {
        if(!root->right && !root->left)
        {
            if(root->val == 1)
            {
                return 1;
            }else{
                root = NULL;
                return 0;
            }                
        }
        
        bool l=false,r=false;
        if(root->left)
        {
            l=helper(root->left);
        }
        if(root->right)
        {
            r=helper(root->right);
        }
        if( ((root->val==1) ||l||r)==false)
        {
            root=nullptr;
            return 0;
        }
        
        return (root->val==1) ||l||r;
        
    }
};