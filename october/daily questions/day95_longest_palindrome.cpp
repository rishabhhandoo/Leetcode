class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans =0;
        
        unordered_map<string,int> opp;
        unordered_map<string,int> same;
        
        
        for(int i=0;i<words.size();i++)
        {
            string og = words[i];
            
            if(words[i][0]==words[i][1])
            {
                same[words[i]]++;
            }
            else
            {
                string sorted = og;
                sort(sorted.begin(),sorted.end());
                
                if(sorted==og)
                {
                    if(opp.find(sorted)!=opp.end())
                    {
                        if(opp[sorted]<0)
                        {
                            ans+=4;
                            
                        }
                    }
                     opp[sorted]++;   
                }
                else
                {
                    if(opp.find(sorted)!=opp.end())
                    {
                        if(opp[sorted]>0)
                        {
                            ans+=4;
                            
                        }
                    }
                     opp[sorted]--;  
                }
                
            }
        }
        
        bool odd = true;
        
        
        for(auto itr : same)
        {
            if(itr.second%2==0)
            {
                ans+=(itr.second)*2;
            }else{
                if(odd==true)
                {
                    ans+=(itr.second)*2;
                    odd=false;
                }else{
                    ans+=(itr.second-1)*2;
                }
            }
        }
        return ans;
        
        
    }
};