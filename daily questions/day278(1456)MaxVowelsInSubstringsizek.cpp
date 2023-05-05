class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int l = 0;
        unordered_map<char,int> umap;
        umap['a']++;
        umap['e']++;
        umap['i']++;
        umap['o']++;
        umap['u']++;
        int count =0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(umap.find(s[i])!=umap.end()) count++; 
            if(i<k-1)
            {
                continue;
            }else{
                ans = max(count,ans);
                if(umap.find(s[i-k+1])!=umap.end()) count--; 
            }
        }
        return ans;
    }
};