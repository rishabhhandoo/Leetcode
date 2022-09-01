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
    void helper(TreeNode* root , int &count , int mx)
    {
        if(root->left==nullptr && root->right == nullptr)
        {
            if(root->val >= mx)
                count++;
            return;
        }
        
        if(root->val >= mx)
        {
            count++;
            mx=root->val;

        }
        // int levelmx=mx;
        
        if(root->left != nullptr)
        {
            helper(root->left,count,mx);
            
        }
        if(root->right != nullptr)
            helper(root->right,count,mx);
        
    }

    int goodNodes(TreeNode* root) {
        //doing a dfs traversal 
        
        if(root==nullptr)    return 0;
        int count=0;
        int mx=root->val;
        helper(root,count,mx);
        return count;
        }
};