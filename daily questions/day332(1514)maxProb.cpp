class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        queue<pair<int,double>> q;
        //make an adj list
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            double weight=succProb[i];

            adj[a].push_back({b,weight});
            adj[b].push_back({a,weight});
        }
        vector<double> vis(adj.size(),0);
        //we have our adj list now
        q.push({start,1});
        vis[start]=1;

        while(!q.empty())
        {
            int sz=q.size();

            for(int i=0;i<sz;i++)
            {
                int node=q.front().first;
                double weight=q.front().second;
                q.pop();
                if(vis[node]>weight)    continue;
                for(auto itr:adj[node])
                {
                    int curr=itr.first;
                    double currw=itr.second;
                    if(vis[curr]<currw*weight)
                    {
                        vis[curr]=currw*weight;
                        q.push({curr,vis[curr]});
                    }
                }
            }
        }
        return vis[end];
    }
};
