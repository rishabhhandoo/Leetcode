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
        vector<vector<int>> ans;

    void helper(TreeNode* root,int target,vector<int> &path){
        if(root==nullptr) return ;
        
        path.push_back(root->val);
        target -= root->val;
        
        if(root->left == nullptr && root->right == nullptr)
        {
            if(target==0) ans.push_back(path);
        }else{
            helper(root->left,target,path);
            helper(root->right,target,path);
        }
        path.pop_back();
    }
    
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        helper(root,targetSum,path);
        return ans;
    }
};