class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        
        int strtx;
        int strty;
        int endx;
        int endy;
        
        int count=n*m;
        
        //initializing these variables
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==1)
                    {
                        strtx=i;
                        strty=j;
                    }else if(grid[i][j]==2)
                    {
                        endx=i;
                        endy=j;
                    }else if(grid[i][j]==-1)
                    {
                        count--;
                    }
                }
            }
        
        helper(strtx,strty,endx,endy,grid,ans,count);
        
        return ans;
    }
    
    void helper(int i,int j,int endx,int endy,vector<vector<int>>& grid,int &ans,int count)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1 )
        {
            return;
        }else if(i==endx && j==endy && count==1)
        {
            ans++;
            return;
        }
        
        grid[i][j]=-1;
        
        helper(i+1,j,endx,endy,grid,ans,count-1);
        helper(i,j+1,endx,endy,grid,ans,count-1);
        helper(i-1,j,endx,endy,grid,ans,count-1);
        helper(i,j-1,endx,endy,grid,ans,count-1);

        grid[i][j]=0;
    }
    
    
    
};