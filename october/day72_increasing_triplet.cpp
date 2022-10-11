class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        int l = INT_MAX;
        int m = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<l)
            {
                l=nums[i];
            }else if(nums[i]>l && nums[i]<m)
            {
                m = nums[i];
            }else if(nums[i]>m){
                return true;
            }
        }
        return false;
    }
};