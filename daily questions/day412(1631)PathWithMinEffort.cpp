class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        vector<vector<int>> dis(n,vector<int> (m,INT_MAX));
        while(!pq.empty())
        {
          int x = pq.top().second.first;
          int y = pq.top().second.second;
          int dist = pq.top().first;
          pq.pop();
          if(x==n-1 && y==m-1)  return dist;
          for(int k=0;k<4;k++)
          {
            int newx = x + dx[k];
            int newy = y + dy[k];
            if(newx>=0 && newy>=0 && newx<n && newy<m)
            {
              int curr = max(dist,abs(heights[newx][newy] - heights[x][y]));
              if(dis[newx][newy]>curr)
              {
                dis[newx][newy]= curr;
                pq.push({curr,{newx,newy}});
              }
            }
          }
        }
        return -1;
    }
};