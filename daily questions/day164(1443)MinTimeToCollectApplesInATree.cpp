class Solution {
public:
    int dfs(int curr,vector<vector<int>> &adj,vector<bool>& hasApple,int n)
    {
        //base case
        if(adj[curr].size()==0){
            cout<<"left node:"<<curr<<endl;
            if(hasApple[curr]==true && curr!=0)    return 2;
            else return 0;
        }

        //returning according to the cases
        int toReturn = 0;
        
        for(int i=0;i<adj[curr].size();i++)
        {
            toReturn +=dfs(adj[curr][i],adj,hasApple,n);
        }

          
        
        cout<<"node"<<curr<<",toReturn:"<<toReturn<<endl;
        if(curr==0) return toReturn;

        if(toReturn>0)  return toReturn + 2;
        else if(toReturn==0 && hasApple[curr]==true)   return 2;  
        else    return 0;
    }
    bool findTrue(vector<bool>& hasApple)
    {
        for(auto itr : hasApple)
        {
            if(itr == true) return true;
        }
        return false;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        int ans = dfs(0,adj,hasApple,n);
        if(ans==0 ){
            if(hasApple[0]==true)    return 0;
            if(findTrue(hasApple))
                return 2*edges.size()-2;
        }
        return ans;
    }
};