class Solution {
public:
    
    
    bool check(int node,vector<vector<int>>& graph,vector<int> color)
    {
        queue<pair<int,int>> q;
        q.push({node,1});
        
        while(!q.empty())
        {
            int curr = q.front().first;
            int clr =  q.front().second;
            q.pop();
            
            for(auto itr : graph[curr])
            {
                if(color[itr]==-1){
                    int choice = (clr==1)? 0:1;
                    q.push({itr,choice});
                    color[itr]=choice;
                }else if(clr==color[itr])
                    {
                        return false;
                    }
                }
            }
        return true;
            
        }
            
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();
        vector<int> color(V+1,-1);
        
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1){
                if(!check(i,graph,color))
                    return false;
            }
        }
        return true;
        
    }
};