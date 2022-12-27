class Solution {
public:
    int helper(int n,vector<int> &dp)
    {
        if(n==0)    return 0;
        if(dp[n]!=-1)   return dp[n];
        int res = n;
        for(int i=1;i*i<=n;i++)
        {
            int temp = i*i;
            
            res=min(res,1+helper(n-temp,dp));
        }
        
        return dp[n]=res;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        
        return helper(n,dp);
    }
};