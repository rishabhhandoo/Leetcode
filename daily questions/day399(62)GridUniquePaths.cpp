class Solution {
public:
    int dp[101][101];
    int helper(int m ,int n)
    {
        if(m==0 && n==0)    return 1;
        else if(m<0 || n<0) return 0;
        else if(dp[m][n]!=-1)   return dp[m][n];
        int val1 = helper(m-1,n);
        int val2 = helper(m,n-1);

        return dp[m][n] = val1 + val2;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return helper(m-1,n-1);
    }
};