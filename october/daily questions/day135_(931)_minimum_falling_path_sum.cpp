class Solution {
public:
    
    int dp[105][105];
    
    bool possible(int i,int j,vector<vector<int>>& a)
    {
        int n = a.size();
        int m = a[0].size();
        if(i<n&&i>=0 && j<m&&j>=0)
        {
                return true;
        }       
        return false;
    }
    
    int helper(int csum,int i,int j,vector<vector<int>>& a)
    {
        if(i == a.size()-1 )  return dp[i][j] = csum+a[i][j];
        if(dp[i][j] != -1)  return csum+dp[i][j];
        
        csum = csum + a[i][j];
        
        //down
        int down = INT_MAX,left=INT_MAX,right=INT_MAX;
        //define possible
        if(possible(i+1,j,a))
        {
            down = helper(csum,i+1,j,a);
        }
        //right
        if(possible(i+1,j+1,a))
        {
            right = helper(csum,i+1,j+1,a);
        }
        //left
        if(possible(i+1,j-1,a))
        {
            left = helper(csum,i+1,j-1,a);
        }
        
        int com =  min(left,right);
        dp[i][j] = min(com,down) - csum+a[i][j];
        return min(com,down);
    }
    
    int minFallingPathSum(vector<vector<int>>& a) {
        
        memset(dp,-1,sizeof(dp));
        
        int ans=INT_MAX;
        
        for(int i=0;i<a[0].size();i++)
        {
            ans=min(ans,helper(0,0,i,a));
        }
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[0].size();j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};