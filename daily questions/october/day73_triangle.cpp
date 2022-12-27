class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size()-2;i++)
        {
            bool flag=true;
            if(nums[i+0]+nums[i+1]>nums[i+2]) flag =flag&&true;
            else flag = false;
            if(nums[i+1]+nums[i+2]>nums[i+0]) flag = flag&&true;
            else flag = false;
            if(nums[i+2]+nums[i+0]>nums[i+1]) flag = flag&&true;
            else flag = false;
            if(flag)    ans = max(ans,nums[i+0]+nums[i+1]+nums[i+2]);
            
        }
        return ans;
    }
};