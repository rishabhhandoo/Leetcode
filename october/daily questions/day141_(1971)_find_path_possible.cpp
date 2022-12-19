class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {    
        unordered_map<int,vector<int>> umap;
        int sz =edges.size();
        int maxi=0;
        if(n<=1)    return true;
        for(int i = 0;i<sz;i++)
        {
            umap[edges[i][0]].push_back(edges[i][1]);
            umap[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0;
        vector<int> vis(n,0);
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node]=1;
            count++;
            cout<<node<<endl;
            for(auto itr : umap[node])
            {
                if(itr==destination)    return true;
                if(vis[itr]==0)
                {
                    q.push(itr);
                    if(itr==destination)    return true;
                    // cout<<"current node value"<<node<<": "<<itr<<endl;
                }
            }

        }

        return false;
    }
};