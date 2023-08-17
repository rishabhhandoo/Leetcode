class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)    q.push({i,j});
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        int dist=0;
        while(!q.empty())
        {
            dist++;
            int sz=q.size();

            for(int i=0;i<sz;i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int newx = r + dx[k];
                    int newy = c + dy[k];
                    if(newy>=0 && newx>=0 && newx<n && newy<m && mat[newx][newy]==1 && vis[newx][newy]==0)
                    {
                        vis[newx][newy]=1;
                        mat[newx][newy]=dist;
                        q.push({newx,newy});
                    }
                }
            }
                cout<<endl;
        }
        return mat;

    }
};