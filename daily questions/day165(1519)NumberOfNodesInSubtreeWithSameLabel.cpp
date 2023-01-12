class Solution {
public:

    vector<int> dfs(int curr,int parent,vector<vector<int>> &adj,string &labels,vector<int> &ans)
    {
        vector<int> nodeCounts(26,0);
        nodeCounts[labels[curr]-'a']=1;

        //traversing the adj list

        for(auto child: adj[curr])
        {
            if(child==parent)   continue;

            vector<int> childNodes = dfs(child,curr,adj,labels,ans);
            //adding the childnodes to parent node aka curr

            for(int i=0;i<26;i++)
            {
                nodeCounts[i]+=childNodes[i];
            }
        }
        ans[curr] = nodeCounts[labels[curr]-'a'];
        return nodeCounts;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        //making adj list 
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n,0);
        dfs(0,-1,adj,labels,ans);
        return ans;
    }
};