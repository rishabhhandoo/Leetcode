class Solution {
public:
    void helper(int count, vector<int> &nums,vector<int> &vis,vector<int> &curr,vector<vector<int>> &ans)
    {
        if(count == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                curr.push_back(nums[i]);
                helper(count+1,nums,vis,curr,ans);
                curr.pop_back();
                vis[i]=0;
            }
        }
        return;

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n,0);
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,nums,vis,curr,ans);
        return ans;
    }
};