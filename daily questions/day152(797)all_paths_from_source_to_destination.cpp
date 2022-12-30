class Solution {
public:

    void dfs(int node , vector<int> &curr,vector<vector<int>> &ans,vector<vector<int>> &graph)
    {
        if(node == graph.size()-1){
            ans.push_back(curr);
            return;
        }

        for(auto itr : graph[node])
        {
            node = itr;
            curr.push_back(itr);
            dfs(node,curr,ans,graph);
            curr.pop_back();
        }

    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //using dfs
        vector<int> curr;
        vector<vector<int>> ans;
        curr.push_back(0);

        for(auto itr : graph[0])
        {
            int node = itr;
            curr.push_back(itr);
            dfs(node,curr,ans,graph);
            curr.pop_back();
        }
        return ans;
    }
};