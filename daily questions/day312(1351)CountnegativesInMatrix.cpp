class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(auto itr:grid)
        {
            ans+= lower_bound(itr.rbegin(),itr.rend(),0)-itr.rbegin();
        }
        return ans;
    }
};