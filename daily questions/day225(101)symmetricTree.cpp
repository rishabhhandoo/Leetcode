
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
    bool helper(TreeNode* l,TreeNode* r)
    {
        if(!l && !r)    return true;
        else if(!l || !r)   return false;
        bool c1 = false;
        bool c2 = false;
        if(l->val == r->val)
        {
            c1= helper(l->left,r->right);
            c2= helper(l->right,r->left);
        }
        return c1&&c2;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)    return true;
        if(root->left && root->right)    return helper(root->left,root->right);
        else if(root->left || root->right)   return false;
        return true;
    }
};