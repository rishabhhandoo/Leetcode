class Solution {
public:
    int dp[1001];
    int helper(vector<int>& nums, int target)
    {
        if(target==0)   return 1;
        if(target<0)    return 0;
        if(dp[target] != -1  ) return dp[target];

        int val=0;
        for(auto itr:nums)
        {
            if(target>= itr)
            {
                val += helper(nums,target-itr);  
            }
        }
        return dp[target] = val;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(nums,target);
    }
};