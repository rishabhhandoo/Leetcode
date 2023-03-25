class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int> vis(n,0);
        queue<int> q;
        vector<vector<int>> adj(n);
        //making adj list
        for(auto itr : edges)
        {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);

        }
        int un_vis=n;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                cout<<"currently working on this node : "<<i<<endl;
                q.push(i);
                vis[i]=1;
                int kon=0;
                while(!q.empty())
                {
                    int node = q.front();
                    cout<<"node : "<<node<<endl;
                    kon++;
                    un_vis--;
                    q.pop();
                    for(auto itr:adj[node])
                    {
                        if(vis[itr]==0)
                        {
                            vis[itr]=1;
                            q.push(itr);
                        }
                    }
                }
                cout<<un_vis<<" "<<kon<<endl;
                ans+=(long long)un_vis*(long long)kon;
            }

        }
        return ans;
    }
};