class Solution {
public:
    
    //Creating a Disjoint set
    
    int findpar(int node,vector<int>&parent)
    {
        if(node==parent[node])
             return node;
        
           return parent[node]=findpar(parent[node],parent); 
    }
    
    void Union(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        u=findpar(u,parent);
        v=findpar(v,parent);
        if(rank[u]<rank[v])
             parent[u]=v;
        else if(rank[u]>rank[v])
            parent[v]=u;
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
        //Applying kruskal Algorithm
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int V = points.size();
        
        multimap<pair<int,int>,int>mp; 
        
        for(int i=0;i<V;i++)
        {
           for(int j=0;j<V;j++)
           {   
             if(i!=j){  
           int xi = points[i][0];
           int xj = points[j][0];
           int yi = points[i][1];
           int yj = points[j][1];
           int cost = abs(xi-xj)+abs(yi-yj); 
           mp.insert({{cost,i},j});       //Sorting By Cost
             }
           }
        }
        
        vector<int>parent(V,0);
        vector<int>rank(V,0);
        
        for(int i=0;i<V;i++)
             parent[i]=i;
        int ans=0;
        
        for(auto it:mp)
        {
            if(findpar(it.first.second,parent)!=findpar(it.second,parent)) //To avoid making of cycles
            {
                ans+=it.first.first;
                Union(it.first.second,it.second,parent,rank);
            }
        }
        
        return ans;
    }
};