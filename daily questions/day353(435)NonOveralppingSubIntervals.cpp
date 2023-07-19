class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = a.size();
        if(n==0||n==1)  return 0;
        sort(a.begin(),a.end());
        int s= a[0][0];
        int e= a[0][1];
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(e<=a[i][0])
            {
                s=a[i][0];
                e=a[i][1];
            }else
            {
                ans++;
                e=min(a[i][1],e);
            }
        }
        return ans;
    }
};