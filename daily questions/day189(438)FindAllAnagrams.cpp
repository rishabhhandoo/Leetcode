class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char,int> pfreq;
        vector<int> ans;
        
        for(int i=0;i<p.size();i++)
        {
            pfreq[p[i]] ++;
        }
        
        int count = pfreq.size();
        
        int i=0,j=0;
        
        while(j<s.size()){
            if(pfreq.find(s[j]) != pfreq.end()){
                pfreq[s[j]]--;
                if(pfreq[s[j]] == 0){
                    count--;
                }
            }
            
            if(j-i+1 < p.size()){
                j++;
            }else if(j-i+1 == p.size()){
                if(count==0){
                    ans.push_back(i);
                }
                if(pfreq.find(s[i]) != pfreq.end()){
                   pfreq[s[i]]++; 
                    if(pfreq[s[i]] == 1){
                    count++;
                    }
                }
                
                i++;
                j++;
            }
        }
        
        return ans;
    }
};