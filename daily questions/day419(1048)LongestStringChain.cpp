class Solution {
public:
    bool comp(string &s1,string &s2)
    {
        int n=s1.size();
        int m=s2.size();
        if(n-m>1 || n-m<=0)  return false;

        int i=0;
        int j=0;
        bool allow=true;
        while((i<n &&j<m)|| allow )
        {
            if(s1[i]!=s2[j])
            {
                allow=false;
                i++;
            }else{
                i++,j++;
            }
        }
        if(i==n && j==m)    return true;
        return false;
    }
    static bool co(string &a,string &b)
    {
        return a.size()<b.size();        
    }
    int longestStrChain(vector<string>& words) {
        int n =words.size();
        sort(words.begin(),words.end(),co);
        vector<int> dp(n,1);

        int maxx=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(comp(words[i],words[j])) 
                {
                    // cout<<words[i]<<" "<<words[j]<<endl; 
                    dp[i] = max(dp[i], 1+dp[j]);
                    maxx=max(dp[i],maxx);
                }
            }
        }
        return maxx;

    }
};