class Solution {
public:
    int dp[105][105];
    int helper(vector<vector<int>>& a,int i,int j)
    {
        int n = a.size(),m=a[0].size();
        if(i>= n || j>=m || a[i][j]==1)  return 0;
        if(i==n-1 && j==m-1)    return 1;
        if(dp[i][j]!=-1)    return dp[i][j];

        int val = helper(a,i+1,j) + helper(a,i,j+1);
        return dp[i][j] = val;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        memset(dp,-1,sizeof(dp));
        return helper(a,0,0);
    }
};