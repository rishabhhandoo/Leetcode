class Solution {
public:
    int dp[21][2*5000 +1];
    int helper(vector<int>& a,int i,int diff)
    {
        if(i==a.size())
        {
            if(diff==0) return 0;
            return INT_MIN;
        }
        else if(dp[i][diff + 5000]!=-1) return dp[i][diff+5000];
        //take 1 2 , not take
        int val1=helper(a,i+1,diff);
        int val2=a[i] + helper(a,i+1,diff+a[i]);
        int val3= helper(a,i+1,diff-a[i]);
        return dp[i][diff+5000] = max({val1,val2,val3});
    }
    int tallestBillboard(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        return helper(a,0,0);
    }
};