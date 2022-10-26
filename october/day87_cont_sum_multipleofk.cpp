class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> umap;
        int n = nums.size();
        umap[0].push_back(-1);
        vector<int> pref;
        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            pref.push_back(sum);
            umap[pref[i]%k].push_back(i);
            
            if(umap[pref[i]%k].size()>1)
            {
                auto aka = umap[pref[i]%k];
                for(int x =0;x<aka.size()-1;x++) 
                {
                    for(int y =0;y<aka.size();y++) 
                    {
                        if(abs(aka[x]-aka[y])>1) return true;
                    }
                }
            }
        }
        return false;
    }
};