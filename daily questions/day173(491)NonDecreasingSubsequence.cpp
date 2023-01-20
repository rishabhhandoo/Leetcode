class Solution {
public:

    void helper(vector<int> &nums,vector<int> curr,int i,int &n,vector<vector<int>> &ans,set<vector<int>> &checker)
    {
        if(i>=n)
        {
            if(curr.size()>=2 && checker.find(curr)==checker.end())
            {
                ans.push_back(curr);
                checker.insert(curr);
            }
            return;
        }
        //take
            if(curr.size()==0 || curr.back()<= nums[i])
            {
                curr.push_back(nums[i]);
                helper(nums,curr,i+1,n,ans,checker);
                curr.pop_back();
            }
        
            helper(nums,curr,i+1,n,ans,checker);
        
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> checker;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> curr;
        helper(nums,curr,0,n,ans,checker);
        return ans;
    }
};