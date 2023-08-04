class Solution {
public:
    bool helper(string &s, unordered_map<string,bool> &umap,int l ,int r)
    {
        if(l>r) return true;
        if(umap.find(s.substr(l,r-l+1))!=umap.end() )  return umap[s.substr(l,r-l+1)];

        for(int i=l;i<=r;i++)
        {
            if(umap[s.substr(l,i-l+1)] >0)
                if(helper(s,umap,i+1,r))    return umap[s.substr(l,r-l+1)] = true;
        }
        return umap[s.substr(l,r-l+1)] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string,bool> umap;
        for(auto itr:wordDict)  umap[itr]=1;
        return helper(s,umap,0,s.size()-1);
    }
};