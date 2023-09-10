class Solution {
public:
    int dp[505][505];
    int helper(int n , int pickup , int deliver)
    {
        //base
        if(pickup > n)  return 0;
        if(deliver == n)    return 1;
        if(dp[pickup][deliver] != -1)   return dp[pickup][deliver];
        int MOD = 1e9+7;
        long long int val =0;

        if(pickup > deliver)    
        {
            val += 1LL*(pickup-deliver)*helper(n,pickup,deliver+1);
            val%=MOD;
        }
        val+=  1LL*(n-pickup)*helper(n,pickup+1,deliver);
        val%=MOD;
        return dp[pickup][deliver] = val;
    }

    int countOrders(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n,0,0);
    }
};