class Solution {
public:
int dp[50001][2];
    int helper(vector<int>& a,int ind,int canbuy ,int fee)
    {
        if(ind==a.size())   return 0;
        else if(dp[ind][canbuy]!= -1)   return dp[ind][canbuy];
        int val=0;
        if(canbuy)
        {
            val = max( -a[ind] + helper(a,ind+1,0,fee) , helper(a,ind+1,1,fee));
        }else{
            val = max( +a[ind] - fee + helper(a,ind+1,1,fee),helper(a,ind+1,0,fee));
        }
        return dp[ind][canbuy] = val;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return helper(prices,0,1,fee);
    }
};