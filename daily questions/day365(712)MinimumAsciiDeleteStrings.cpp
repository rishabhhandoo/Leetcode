class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = s1[i-1] + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //dp table made now we have to do the main traversal
        int ans=0;
        // int i=n;
        // int j=m;
        // while(i>0 && j>0)
        // {
        //     if(s1[i-1]==s2[j-1])a
        //     {
        //         i--,j--;
        //     }else if(dp[i-1][j]< dp[i][j-1])
        //     {
        //         ans+= (int)s2[j-1];
        //         j--;
        //     }else if(dp[i-1][j] > dp[i][j-1])
        //     {
        //         ans+= (int)s1[i-1];
        //         i--;
        //     }else if(s1[i-1]<s2[j-1])
        //     {
        //         ans+= (int)s1[i-1];
        //         i--;
        //     }else 
        //     {
        //         ans+= (int)s2[j-1];
        //         j--;
        //     }
        // }
        // while(i>0)
        // {
        //     ans+= (int)s1[i-1];
        //     i--;
        // }
        // while(j>0)
        // {
        //     ans+= (int)s2[j-1];
        //     j--;
        // }
        int summ1=0;
        int summ2=0;
        for(auto itr:s1)    summ1+= (int)(itr);
        for(auto itr:s2)    summ2+= (int)(itr);
        return summ1 + summ2 - (2*dp[n][m]);
    }
};