class Solution {
public:
    int largestVariance(string s) {
        int n=s.size();
        int ans=0;
        //so we wll make pair of 2 characters
        for(char i = 'a' ; i<='z' ; i++)
        {
            for(char j = 'a';j<='z' ; j++)
            {
                if(j==i)    continue;
                //now we iterate over the string to check these 2 pairs
                for(int u=0;u<=1;u++){
                    int ci=0;
                    int cj=0;
                    for(int k=0;k<n;k++)
                    {
                        if(i==s[k]) ci++;
                        else if(j==s[k])    cj++;
                        if(ci-cj<0)
                        {
                            ci=0;
                            cj=0;
                        }
                        if(ci>0 && cj>0)
                        {
                            ans=max(ans,ci-cj);
                        }
                    }
                    reverse(s.begin(),s.end());
                }
            }

        }
        return ans;
    }
};