class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string w1="";
        string w2="";
        
        for(auto word :word1)
        {
            w1+=word;
        }
        for(auto word :word2)
        {
            w2+=word;
        }
        
        return w1==w2;
        
    }
};