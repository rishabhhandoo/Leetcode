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
    TreeNode* helper(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe,unordered_map<int,int>& umap)
    {
        if(is>ie || ps>pe)  return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int index = umap[postorder[pe]];
        root->left = helper(inorder,is,index-1,postorder,ps,ps+index-1-is,umap);
        root->right = helper(inorder,index+1,ie,postorder,ps+index-is,pe-1,umap);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> umap;
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            umap[inorder[i]]=i;
        }

        return helper(inorder,0,n-1,postorder,0,n-1,umap);
    }
};
