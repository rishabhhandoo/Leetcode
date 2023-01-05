class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(),points.end());
        int strt = points[0][0];
        int end = points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>end)
            {
                cout<<"entered"<<endl;
                ans++;
                strt=points[i][0];
                end=points[i][1];
            }else{
                end=min(points[i][1],end);
                strt=max(points[i][0],strt);
            }
        }
        return ans+1;
    }
};