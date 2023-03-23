class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      vector<vector<int>> adj(n);
        if(n-1>connections.size())    return -1;
      for(auto itr : connections)
      {
          adj[itr[0]].push_back(itr[1]);
          adj[itr[1]].push_back(itr[0]);
      }
      //adj list is made
      //now ig ill have to find the number of disconnected components
    
    int ans=0;
    queue<int> q;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            cout<<"value of i for entering : "<<i<<endl;
            ans++;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                //check for adj nodes
                for(auto itr:adj[node])
                {
                    if(vis[itr]==0)
                    {
                        cout<<"pushing it in"<<itr<<endl;
                        q.push(itr);
                        vis[itr]=1;
                    }
                }
            }
        }   
    }
    return ans-1;
    }
};