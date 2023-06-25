class Solution {
public:
    int dp[105][205];
    const int MOD=1e9+7;
    int helper(vector<int>& a, int start, int finish, int fuel)
    {
        //base case
        long long int val =0;
        if(fuel <0) return 0;
        if(start==finish)
        {
            val++;
        }
        if(dp[start][fuel]!=-1) return dp[start][fuel];

        for(int i=0;i<a.size();i++)
        {
            if(i!=start)
            {
                val += helper(a,i,finish,fuel - abs(a[start] - a[i]));
                val%=MOD;
            }
        }
        return dp[start][fuel] = val;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return helper(locations,start,finish,fuel);
    }
};