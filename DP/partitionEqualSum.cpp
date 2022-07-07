class Solution {
public:
    int dp[205][20005];
    
    bool helper(int ind,int sum,vector<int> &nums)
    {
        if(sum==0) return 1;
        if(ind<0)  return 0;
        
        if(dp[ind][sum] != -1 )  return dp[ind][sum];
        bool take = 0;
        if(sum>=nums[ind])
            take = helper(ind-1,sum-nums[ind],nums);
        bool notTake = helper(ind-1,sum,nums);
        
        return dp[ind][sum] = (take || notTake);
    }
    
    
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2 != 0)  return false; 
        
        sum=sum/2;
        
        return helper(nums.size()-1,sum,nums);
    }
};