class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans=0;
        queue<pair<int,int>> q;
        vector<vector<int>> adj (n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        q.push({headID,informTime[headID]});
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto node = q.front();
                q.pop();
                if(adj[node.first].size()==0)   ans = max(ans , node.second);
                for(auto itr: adj[node.first])
                {
                    q.push({itr,node.second+informTime[itr]});
                }
            }
        }
        return ans;
    }
};