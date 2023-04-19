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
    int ans = INT_MIN;
    void helper(bool lane , int val , TreeNode* root)
    {

        if(root==nullptr)   {
            ans = max(val-1,ans);
            return;
        }
        if(lane)
        {
            // we go left
            helper(!lane,val+1,root->left);
            helper(lane,1,root->right);
        }else{
            helper(!lane,val+1,root->right);
            helper(lane,1,root->left);
        }
        return;
    }
    int longestZigZag(TreeNode* root) {
        //here lane = true means left jao and false means right jao
        bool lane=true;
        helper(lane,0,root);
        return ans;
    }
};