class Solution {
public:
    bool helper(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0 )
        {
            return false;
        }
        
        if(grid[i][j]==1|| vis[i][j]==1)
        {
            return true;
        }
        vis[i][j]=1;
        //now go for the up right left bottom
        bool val1 =  helper(i+1,j,grid,vis);
        bool val2 =  helper(i,j+1,grid,vis); 
        bool val3 =  helper(i-1,j,grid,vis); 
        bool val4 = helper(i,j-1,grid,vis);
        
        return val1 && val2 && val3 && val4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0 && !vis[i][j])
                {
                    ans+=(helper(i,j,grid,vis)==true?1:0);  
                }
            }
        }
        return ans;
    }
};


// [0,0,1,1,0,1,0,0,1,0]
// [1,1,0,1,1,0,1,1,1,0]
// [1,0,1,1,1,0,0,1,1,0
// [0,1,1,0,0,0,0,1,0,1]
// [0,0,0,0,0,0,1,1,1,0]
// [0,1,0,1,0,1,0,1,1,1]
// [1,0,1,0,1,1,0,0,0,1]
// [1,1,1,1,1,1,0,0,0,0]
// [1,1,1,0,0,1,0,1,0,1]
// [1,1,1,0,1,1,0,1,1,0]]

