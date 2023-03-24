class Solution {
public:
    void helper(int curr,vector<int> &vis ,vector<vector<int>>& ud_adj,vector<vector<int>>& d_adj,int &ans)
    {
        //i am at an unvisited node
        vis[curr]=1;
        
        for(auto node: ud_adj[curr])
        {
            if(vis[node]==0)
            {
                //if the direction matches aka we have to reverse it 
                if(find(d_adj[curr].begin(), d_adj[curr].end(), node)!=d_adj[curr].end())   ans++;
                helper(node,vis,ud_adj,d_adj,ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
            //num of cities and n-1 connections

            //making an adj list
            vector<vector<int>> un_adj(n);
            vector<vector<int>> d_adj(n);

            for(auto itr: connections)
            {
                //undirected
                un_adj[itr[0]].push_back(itr[1]);
                un_adj[itr[1]].push_back(itr[0]);
                d_adj[itr[0]].push_back(itr[1]);
            }
            //adj list made
            //just do a dfs
            int ans=0;
            vector<int> vis(n,0);
            helper(0,vis,un_adj,d_adj,ans);
            return ans;
    }
};