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
    bool isCompleteTree(TreeNode* root) {
        bool stop=false;

        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty())
        {
            int k = q.size();
            
            for(int i=0;i<k;i++)
            {
                TreeNode* node = q.front();
                cout<<node->val<<endl;
                q.pop();
                if(stop){
                    cout<<"case 1 :"<<"if(node->left && node->right)"<<endl;
                    if(node->left!=NULL || node->right!=NULL)   return false;
                }else{
                    if(node->left==NULL && node->right!=NULL)
                    {
                        cout<<"case 2: !node->left && root->right"<<endl;
                        return false;
                    }
                    else if(node->left==NULL || node->right==NULL)
                    {
                        cout<<"case3: !node->left && !node->right"<<endl;
                        stop=true;
                    }

                    if(node->left)  q.push(node->left);
                    if(node->right)  q.push(node->right);
                }
            }
        }
        return true;


    }
};