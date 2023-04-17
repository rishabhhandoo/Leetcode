class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxx=0;
        for(auto itr : candies)
        {
            maxx = max(maxx,itr);
        }
        for(auto itr : candies)
        {
            ans.push_back(itr+extraCandies>=maxx?true:false);
        }
        return ans;
    }
};