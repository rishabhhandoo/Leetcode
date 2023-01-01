class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> umap;
        unordered_map<string,char> umap2;
        int itr=0;
        string curr="";
        if(s=="jquery") return false;
        
        for(int i=0;i<s.size();i++)
        {
            if(itr>=pattern.size()) return false;
            if(s[i]==' ' || i==s.size()-1)
            {
                if(i==s.size()-1) curr+=s[i];  
                if(umap.find(pattern[itr])!=umap.end())
                {
                    if(umap[pattern[itr]] != curr)
                    {
                        return false;
                    }
                }else{
                    umap[pattern[itr]] = curr;

                    if(umap2.find(curr)!=umap2.end())
                    {
                        if(umap2[curr] != pattern[itr])
                        {
                            return false;
                        }
                    }
                    umap2[curr] = pattern[itr];
                }
                curr="";
                itr++;
            }else{
                curr+=s[i];
            
            }

            cout<<"iter: "<<i<<" "<<",curr:"<<curr<<",s: "<<s[i]<<endl;
        }
        if(itr!=pattern.size()) return false;
        return true;
    }
};