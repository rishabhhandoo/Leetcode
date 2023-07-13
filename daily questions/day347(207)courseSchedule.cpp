class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
       //just have to see for cycle in directed graph
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        // vector<int> vis(n,0);
        for(auto itr: a)
        {
            ind[itr[0]]++;
            adj[itr[1]].push_back(itr[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)   q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto itr:adj[node])
            {
                // if(vis[itr]==0)
                // {
                    // vis/
                    ind[itr]--;
                    if(ind[itr]==0)
                    {
                        q.push(itr);
                    }
                // }
            }
        }
        for(auto itr:ind)   if(itr!=0)  return false;
        return true;
    }
};