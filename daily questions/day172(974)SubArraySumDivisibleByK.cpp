class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int curr=0;
        int ans=0;
        umap[0]++;
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            int rem = curr%k;
            if(rem <0)  rem +=k;
            
            if(umap.find(rem) != umap.end())
            {
                ans+=umap[rem];
            }
            
            umap[rem]++;
        }
        return ans;
    }
};