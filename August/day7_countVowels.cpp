class Solution {
public:

    const long long mod = 1e9+7;
    long long dp[27][20002];
    // vector<vector<int>> dp;
    
    long long helper(long long n,long long prevchar){
        
        if(n==0)    return 1;
        // if(dp[n][prevchar] != -1)    return dp[n][prevchar];
        if(dp[prevchar][n] != -1)    return dp[prevchar][n];
        
        long long a=0,e=0,i=0,o=0,u=0;
        
        switch(prevchar)
        {
            case 1: 
                e=(helper(n-1,2)%mod);
                break;
            case 2: 
                a=(helper(n-1,1)%mod);
                i=(helper(n-1,3)%mod);
                break;
            case 3: 
                a=(helper(n-1,1)%mod);
                e=(helper(n-1,2)%mod);
                o=(helper(n-1,4)%mod);
                u=(helper(n-1,5)%mod);
                break;
            case 4: 
                i=(helper(n-1,3)%mod);
                u=(helper(n-1,5)%mod);                
                break;
            case 5: 
                a=(helper(n-1,1)%mod);
                break;
            default: 
                a=(helper(n-1,1)%mod);
                e=(helper(n-1,2)%mod);
                i=(helper(n-1,3)%mod);
                o=(helper(n-1,4)%mod);
                u=(helper(n-1,5)%mod);
                break;       
        }
        return dp[prevchar][n] = ((a+e+i+o+u)%mod);
    }
    
    int countVowelPermutation(int n) {
        
        // memset(dp,-1,sizeof(dp));
        // dp.resize(n+1,vector<int>(5,-1));
        memset(dp,-1,sizeof(dp));
        
        long long prevchar=0;
        
        return helper(n,prevchar);
    }
};