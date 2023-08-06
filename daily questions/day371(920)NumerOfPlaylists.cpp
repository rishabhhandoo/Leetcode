class Solution {
public:
    int dp[105][105];
    int mod=1e9+7;
    long long int helper(int goal,int usedSongs,int n,int k)
    {
        if(goal==0)
        {
            return n==usedSongs;
        }
        if(dp[goal][usedSongs]!=-1) return dp[goal][usedSongs];

        long long int oldSongs = helper(goal-1,usedSongs,n,k) * max(0,usedSongs-k);
        oldSongs%=mod;
        long long int newSongs = helper(goal-1,usedSongs+1,n,k) * (n-usedSongs);
        newSongs%=mod;

        return dp[goal][usedSongs] = oldSongs + newSongs;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(goal,0,n,k);
    }
};