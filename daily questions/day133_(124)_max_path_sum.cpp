int max_val=INT_MIN;
int helper(TreeNode* root)
{
    if(!root)return 0;
        int l=max(helper(root->left),0);
        int r=max(helper(root->right),0);
        int new_price=root->val+l+r;
        max_val=max(max_val,new_price);
        cout<<max_val<<endl;
        return root->val+max(l,r);
}