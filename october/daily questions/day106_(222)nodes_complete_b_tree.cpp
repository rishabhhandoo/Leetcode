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
    int countNodes(TreeNode* root) {
        if(root==nullptr)   return 0;
        
        int lc = count_left(root);
        int rc = count_right(root);
        
        if(lc==rc)  return pow(2,lc) -1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);       
    }
    
    int count_left(TreeNode* node)
    {
        int height=0;
        
        while(node)
        {
            height++;
            node=node->left;
        }
        return height;
    }
    
    int count_right(TreeNode* node)
    {
        int height=0;
        
        while(node)
        {
            height++;
            node=node->right;
        }
        return height;
    }
    
};