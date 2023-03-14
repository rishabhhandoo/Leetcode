class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int> pref;
        int n= nums.size();
        int xorr=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            xorr = xorr^nums[i];
            if(xorr==0)
            {
                ans++;
            }
            if( pref.find(xorr)!=pref.end())    ans+=pref[xorr];
            pref[xorr]++;
        }
        return ans;
    }
};