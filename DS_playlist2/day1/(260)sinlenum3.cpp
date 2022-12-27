class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int d=0;

        for(auto num : nums)
        {
            d=d^num;
        }
        // int s = d & -d; this didnt work in case of -2e31
        int s;
        for (int i=0; i<32; ++i) {
            if (d & (1<<i)) {
                s = d & (1<<i);
                break;
            }
        }

        vector <int> ans(2,0);
        for(auto num:nums)
        {
            if(s &  num )
            {
                ans[0]^=num;
            }
            else{
                ans[1]^=num;
            }
        }
        return ans;
    }
};