class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> umap;
        unordered_map<char,int> ind;
        for(int i=0;i<s.size();i++)
        {
            umap[s[i]]++;
            ind[s[i]]=i;
        }
        for(int i=0;i<s.size();i++)
        {
            if(umap[s[i]]==1){
                return ind[s[i]];
            }
        }
        return -1;
    }
};