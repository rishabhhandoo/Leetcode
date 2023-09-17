class Solution {
public:
    int shortestPathLength(vector<vector<int>>& a) {
        int n = a.size();
        int mask = 0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            vector<vector<int>> vis(n,vector<int> ((1<<a.size()),-1));
            int newmask = mask | (1<<i);
            queue<pair<int,pair<int,int>>> q;
            q.push({i,{newmask,0}});
            while(!q.empty())
            {
                int node = q.front().first;
                int currmask = q.front().second.first;
                int steps = q.front().second.second;
                q.pop();
                if(currmask == (1<<a.size())-1)   
                {
                    ans = min(ans,steps);
                    break;
                } 
                for(auto adjN : a[node])
                {
                    int newMask = currmask | (1<<adjN);
                    if(vis[adjN][newMask] == -1)    
                    {
                        vis[adjN][newMask]=1;
                        q.push({adjN,{newMask,steps+1}});
                    }
                }
            } 
        }
        return ans;
    }
};