class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> umap;
        
        for(int i=0;i<magazine.size();i++)
        {
            umap[magazine[i]]++;
        }
        
        for(int i=0;i<ransomNote.size();i++)
        {
            if(umap.find(ransomNote[i]) != umap.end())
            {
                umap[ransomNote[i]]--;
                if(umap[ransomNote[i]]==0)
                {
                    umap.erase(ransomNote[i]);
                }
            }else return false;
        }
        
        return true;
    }
};