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
    void inorder(TreeNode* root,vector<int> &temp )
    {
        if(root==NULL)  return;
        
        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }
    bool findTarget(TreeNode* root, int target) {
        vector<int> temp;
        
        inorder(root,temp);
        int n = temp.size();
        int l=0;
        int r=n-1;
        int sum=0;
        while(l<r)
        {
            sum=temp[l]+temp[r];
            
            if(sum>target)
            {
                r--;
            }
            else if(sum<target)
            {
               l++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};