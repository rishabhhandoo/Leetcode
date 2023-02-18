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
    vector<int> value;
    void inorder(TreeNode* root)
    {
        if(!root)   return;
        inorder(root->left);
        value.push_back(root->val);
        inorder(root->right);
        
        // return;
        
    }        
        
    bool isValidBST(TreeNode* root) {
        
        inorder(root);
        
        for(int i=1;i<value.size();i++)
        {
            if(value[i-1]>=value[i]) return false;
        }
        
        return true;
    }
};