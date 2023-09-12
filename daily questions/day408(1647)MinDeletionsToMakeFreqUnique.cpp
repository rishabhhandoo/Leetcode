class Solution {
public:
    int minDeletions(string s) {
        vector<long long int> c(26,0);
        long long int maxx=0;
        for(auto itr:s) 
        {
            c[itr-'a']++;
            maxx= max(maxx,c[itr-'a']);
        }
        vector<long long int> freq(maxx+1,0);
        for(int i=0;i<26;i++)
        {
            freq[c[i]]++;
        }
        long long int ans=0;
        for(int i=maxx;i>0;i--)
        {
            if(freq[i]>1)
            {
                freq[i-1]+= (freq[i]-1);
                ans += freq[i]-1;
            }
        }
        return ans;
    }
};
