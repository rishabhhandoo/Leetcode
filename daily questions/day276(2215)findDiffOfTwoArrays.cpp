class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> s1;
        unordered_set<int> s2;

        for(auto itr : nums1)
            s1.insert(itr);
        for(auto itr : nums2)
            s2.insert(itr);

        for(auto itr: s1)
        {
            if(s2.find(itr)==s2.end())
            {
                ans[0].push_back(itr);
            }
        }
        for(auto itr: s2)
        {
            if(s1.find(itr)==s1.end())
            {
                ans[1].push_back(itr);
            }
        }
        return ans;
    }
};