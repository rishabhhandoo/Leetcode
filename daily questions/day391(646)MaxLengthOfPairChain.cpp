class Solution {
public:
    static bool comp(vector<int> a,vector<int> b)
    {
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int n = pairs.size();
        vector<int> dp(n+1,1);
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1]<pairs[i][0])
                {
                    dp[i]= max(dp[i] , 1+ dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};