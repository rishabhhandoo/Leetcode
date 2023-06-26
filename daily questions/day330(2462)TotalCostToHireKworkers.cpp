class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        long long int n = costs.size();
        vector<int> vis(n,0);
        long long int l=0;
        for(int i=0;i<c;i++)
        {
            if(vis[i]==0)
            {
                pq.push({(costs[i]),i,0});
                vis[i]=1;
            }
            l=i;
        }

        l++;
        long long r=0;
        for(int i=0;i<c;i++)
        {
            if(vis[n-1-i]==0)
            {
                pq.push({(costs[n-1-i]),n-1-i,1});
                vis[n-1-i]=1;
            }
            r=n-1-i;
        }
        r--;
        long long ans=0;
        while(k--)
        {
            auto curr = pq.top();
            // cout<<curr[0]<<" ind: "<<curr[1]<<endl;
            pq.pop();
            ans+=curr[0];
            if(l<n && curr[2]==0 && vis[l]==0)
            {
                pq.push({costs[l],l,0});
                vis[l]=1;
                l++;
            }
            if(r>=0 && curr[2]==1 && vis[r]==0)
            {
                pq.push({costs[r],r,1});
                vis[r]=1;
                r--;
            }
        }
        return ans;
        
    }
};