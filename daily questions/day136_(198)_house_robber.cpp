class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        int dp=nums[0],dp1=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++)
        {
            int temp = max(dp1,nums[i]+dp);
            dp=dp1;
            dp1=temp;
        }
        return dp1;
    }
};