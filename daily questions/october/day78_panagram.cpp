class Solution {
public:
    bool checkIfPangram(string sentence) {
        //97->122
        unordered_map<char,int> umap;
        
        for(auto itr = 'a';itr<='z';itr++)
        {
            umap[itr]++;
            
        }
        int check = umap.size();
        
        for(int i=0;i<sentence.size();i++)
        {
            if(umap.find(sentence[i]) != umap.end())
            {
                umap[sentence[i]]--;
                if(umap[sentence[i]] == 0) check--;
            }else{
                return false;
            }
        }
        
        if(check==0) return true;
        else return false;
        
    }
};