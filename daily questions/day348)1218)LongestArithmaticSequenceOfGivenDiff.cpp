class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> umap;
        int ans=1;
        for(auto itr:arr)
        {
            // umap[itr]=1;
            if(umap.count(itr-diff))
            {
                umap[itr]=umap[itr-diff]+1;
            }else umap[itr]=1;
            ans = max(ans,umap[itr]);
        }
        return ans;
    }
};