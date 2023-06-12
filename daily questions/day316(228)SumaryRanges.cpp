class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        vector<string> ans;
        int n=a.size();
        if(n==0)    return ans;
        int l=0;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]+1 != a[i])
            {
                string curr="";
                if(i-l>1)
                {
                    curr+=to_string(a[l]);
                    curr+="->";
                    curr+=to_string(a[i-1]);
                    ans.push_back(curr);
                }else{
                    curr+=to_string(a[l]);
                    ans.push_back(curr);
                }
                l=i;
            }
        }

            string curr="";
            if(n-l>1)
            {
                curr+=to_string(a[l]);
                curr+="->";
                curr+=to_string(a[n-1]);
                ans.push_back(curr);
            }else{
                curr+=to_string(a[l]);
                ans.push_back(curr);
            }

        return ans;
    }
};