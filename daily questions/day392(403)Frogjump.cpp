class Solution {
public:
    int dp[2005][2005];
    bool helper(vector<int> &a,unordered_map<int,int> &umap,int i,int k)
    {
        int n=a.size();
        if(i==n-1) return true;
        else if(i>=n)   return false;
        else if(dp[i][k]!=-1)   return dp[i][k];

        bool val = false;
        if(k-1>0 && umap.find(a[i]+k-1)!=umap.end())
            val = val || helper(a,umap,umap[a[i] + (k-1)],k-1);
        if(k>0 && umap.find(a[i]+k)!=umap.end())
            val = val || helper(a,umap,umap[a[i] + (k)],k);
        if(k+1>0 && umap.find(a[i]+k+1)!=umap.end())
            val = val || helper(a,umap,umap[a[i] + (k+1)],k+1);

        return dp[i][k] = val;

    }
    bool canCross(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        unordered_map<int,int> umap;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            umap[a[i]]=i;
        }
        if(a[1]>1)  return false;
        return helper(a,umap,1,1);
    }
};

          
