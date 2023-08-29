class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        vector<int> cy(n+1,0);
        vector<int> cn;
        int c=0;
        for(int i=0;i<n;i++)
        {
            cn.push_back(c);
            if(s[i]=='N')   c++;
        }
        cn.push_back(c);
        c=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='Y')   c++;
            cy[i]=c;
        }
        int ans=INT_MAX;
        int val=0;
        for(int i=0;i<n+1;i++)
        {
            if(ans> cn[i]+cy[i])
            {
                ans=cn[i]+cy[i];
                val=i;
            }
        }
        return val;
    }
};