class Solution {
public:
    unordered_map<string,int> umap;
    bool helper(string s1 , string s2)
    {
        if(s1==s2)  return true;
        if(s1.size()==0 || s2.size()==0)    return false;
        int n = s1.size();
        string key = s1 +" "+ s2;
        if(umap.find(key)!=umap.end())
        {
            return umap[key];
        }
        //main function
        for(int i=1;i<n;i++)
        {
            if(
                    ( helper(s1.substr(0,i),s2.substr(n-i,i)) && helper(s1.substr(i,n-i) ,s2.substr(0,n-i)) )
                ||
                    ( helper(s1.substr(0,i),s2.substr(0,i))   && helper(s1.substr(i,n-i),s2.substr(i,n-i)) )
              )
                {
                    return umap[key] = true;
                }
        }
        return umap[key] =false;

    }

    bool isScramble(string s1, string s2) {


        if(s1.size()!=s2.size())    return false;
        if(s1==s2)  return true;
        if(s1.size()<=1)    return false;    
        return helper(s1,s2);

    }
};