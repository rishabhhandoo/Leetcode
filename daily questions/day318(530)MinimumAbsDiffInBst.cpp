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
    int helper(TreeNode* root,int &minn,int &prev)
    {
       if(root==nullptr)    return minn;
       helper(root->left,minn,prev);
       if(prev!=INT_MAX)
       {
           minn=min(minn,abs(root->val - prev));
       }
       prev=root->val;
       helper(root->right,minn,prev);
       return minn;
    }
    int getMinimumDifference(TreeNode* root) {
       int minn = INT_MAX;
       int prev=INT_MAX;
       helper(root,minn,prev); 
       return minn;
    }
};