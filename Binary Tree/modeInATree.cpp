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
    unordered_map<int,int> umap;
    
    void inorder(TreeNode* root,int &maxx)
    {
            if(!root)   return;
        
        inorder(root->left,maxx);
        
        umap[root->val]++;
        maxx = max(maxx,umap[root->val]);

        inorder(root->right,maxx);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(!root)   return ans;
        int maxx=0;
        inorder(root,maxx);
        
        for(auto itr : umap)
        {
            if(itr.second == maxx)
            {
                ans.push_back(itr.first);
            }
        }
        return ans;
        
        
    }
};