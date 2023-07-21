class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //basic approach of n^2
        //so we just form the lis and see the number times same increasing sequence is formed
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> times(n,1);
        int maxx=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && 1+dp[j]>dp[i])
                {
                    dp[i]=dp[j]+1;
                    times[i] = times[j];
                }else if(nums[i]>nums[j] && 1+dp[j]==dp[i])
                {
                    times[i]+=times[j];
                }
            }
            maxx=max(maxx,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxx)
            {
                ans+=times[i];
            }
        }
        return ans;
    }
};