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
    bool helper(TreeNode* lroot, TreeNode* rroot){
        
        if(!rroot && !lroot){
            return true;
        }else if(!rroot || !lroot){
            return false;
        }     
        
        if(lroot->val != rroot->val){
            return false; 
        }
        return helper(lroot->left,rroot->right) && helper(lroot->right,rroot->left); ;
       
    }
    
    bool isSymmetric(TreeNode* root) {
        TreeNode* lroot = root->left;
        TreeNode* rroot = root->right;
        
        return helper(lroot,rroot);

    }
};