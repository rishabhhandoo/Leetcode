class Solution {
public:
int dp[5001][301];
    int helper(vector<int> &nums,int amount,int n)
    {
        if(amount==0)   return 1;
        else if(n==0)
        {
            if(amount%nums[n]==0)   return 1;
            else return 0;
        }else if(dp[amount][n]!=-1) return dp[amount][n];

        ///take not take
        int val=0;
        if(nums[n]<=amount)
        {
            val = helper(nums,amount-nums[n],n) + helper(nums,amount,n-1);
        }else
        {
            val = helper(nums,amount,n-1);
        }
        return dp[amount][n] = val;
    }
    int change(int amount, vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return helper(nums,amount,n-1);
    }
};