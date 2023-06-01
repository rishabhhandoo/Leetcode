class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0]==1)   return -1;
        q.push({0,{0,0}});
        vector<vector<bool>> vis(n,vector<bool> (m,0));
        vis[0][0]=true;
        while(!q.empty())
        {
            int sz= q.size();
            int val = q.front().first;
            int row = q.front().second.first,col = q.front().second.second;
            q.pop();
            if(row==n-1 && col ==m-1)   return val+1;
            for(int i=0;i<sz;i++)
            {
                for(int dr=-1;dr<2;dr++)
                {
                    for(int dc=-1;dc<2;dc++)
                    {
                        int newR=row + dr;
                        int newC=col + dc;
                        
                        if(newR>=0 && newR<n && newC >=0 && newC<m && vis[newR][newC]==false && grid[newR][newC]==0)
                        {
                            // cout<<"val :"<<val<<" "<<"row and col "<<row<<" "<<col<<" new row and col: "<<newR<<" "<<newC<<endl;
                            vis[newR][newC]=true;
                            q.push({val+1,{newR,newC}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};