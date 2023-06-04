class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        queue<int> q;
        vector<bool> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                q.push(i);
                vis[i]=1;
                ans ++;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for(auto itr: adj[node])
                    {
                        if(vis[itr]==0)
                        {
                            q.push(itr);
                            vis[itr]=1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};