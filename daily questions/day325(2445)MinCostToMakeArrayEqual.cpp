class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long int ans=0,summ=0,total=0;
        long long int n=nums.size();

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            summ=summ+ (long long)v[i].second;
        }
        long long median;
        int i=0;
        while(total<(summ+1)/2 && i<n)
        {
            total = total+(long long)v[i].second;
            median=v[i].first;
            i++;
        }
        for(int i=0;i<n;i++)
        {
            ans+=abs(1ll*nums[i]-median)*(1ll*cost[i]);
        }
        return ans;
    }
};