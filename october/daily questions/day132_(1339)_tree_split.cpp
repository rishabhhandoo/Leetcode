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
 
static int MOD=1e9+7;
class Solution {
public:

    int bfs(TreeNode* root, vector<int> &store)
    {
        if(root==NULL)
        {
            return 0;
        }

        long long int sum1 = bfs(root->left,store);
        long long int sum2 = bfs(root->right,store);
        store.push_back(sum1+sum2+root->val);

        return sum1+sum2+root->val;
    }
    int maxProduct(TreeNode* root) {
        vector<int> store;

        long long int net = bfs(root,store);
        long long int ans=0;
        for(int i=0;i<store.size();i++)
        {
            long long int  temp = store[i]*(net - store[i]) ;
            ans = max(ans,temp);
        }
        return ans%MOD ;
    }
};