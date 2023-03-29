class Solution {
public:
    int dp[501][501];
    int helper(int i , int order_num,vector<int>& satisfaction)
    {
        if(i>=satisfaction.size())  return 0;
        if(dp[i][order_num]!=-1)    return dp[i][order_num];
        //take not take
        return dp[i][order_num]=max(satisfaction[i]*order_num + helper(i+1,order_num+1,satisfaction) ,helper(i+1,order_num,satisfaction));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp,-1,sizeof(dp));
        sort(satisfaction.begin(),satisfaction.end());
        return helper(0,1,satisfaction);
    }
};