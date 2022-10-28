class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> umap;
        
        for(int i=0;i<strs.size();i++)
        {
            string letter = strs[i];
            string code = "00000000000000000000000000";
            for(auto itr : letter)
            {
                int index = itr - 'a';
                code[index] += 1;
            }
            umap[code].push_back(letter);
        }
        
        vector<vector<string>> ans;
        
        for(auto itr : umap)
        {
            ans.push_back(itr.second);
        }
        
        return ans;
    }
};