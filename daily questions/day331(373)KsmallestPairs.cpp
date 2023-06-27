class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
        int n=nums1.size();
        int m=nums2.size();
        int summ = nums1[0]+nums2[0];
        pq.push({summ,{0,0}});
        set<pair<int,int>> vis;
        vector<vector<int>> ans;
        vis.insert({0,0});

        while(k-- && !pq.empty())
        {
            int val = pq.top().first;
            int i= pq.top().second.first;
            int j= pq.top().second.second;
            
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            
            // cout<<nums1[i]<<" "<<nums2[j-1]<<endl;
            if(j+1<m && vis.find({i,j+1})==vis.end())
               { 
                   int summ1= nums1[i]+nums2[j+1];
                    pq.push({summ1,{i,j+1}});
                    vis.insert({i,j+1});
                }
            if(i+1<n && vis.find({i+1,j})==vis.end())
                {
                    int summ2=nums1[i+1]+nums2[j];
                    pq.push({summ2,{i+1,j}});
                    vis.insert({i+1,j});
                }
            // if(j+1<m && i+1<n && vis[i+1][j+1]==0)
            //     {
            //         int summ3=nums1[i+1]+nums2[j+1];
            //         pq.push({summ3,{i+1,j+1}});
            //         vis[i+1][j+1]=1;
            //     }
        }
        return ans;
    }
};