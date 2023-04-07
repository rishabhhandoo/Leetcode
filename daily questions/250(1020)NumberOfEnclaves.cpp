class Solution {
public:
    int final =0;
    bool helper(vector<vector<int>>& grid,int i,int j,int &ans)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m || i<0 || j<0)  return false;
        if(grid[i][j]==0)   {
            return true;
            }
        if(grid[i][j]==1)   {
            ans++;
            grid[i][j]=0;
        }
        //aan we just have to traverse
        bool u = helper(grid,i+1,j,ans);
        bool d = helper(grid,i-1,j,ans);
        bool r = helper(grid,i,j+1,ans);
        bool l = helper(grid,i,j-1,ans);
        return u&&d&&r&&l;

    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {   int ans=0;
                    if(helper(grid,i,j,ans))  final +=ans;
                }
            }
        }
        
        return final ;
    }
};