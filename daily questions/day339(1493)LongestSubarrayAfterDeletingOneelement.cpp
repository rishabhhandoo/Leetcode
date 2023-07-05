class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=2;
        int n=nums.size();
        int l =0,r=0;
        int ans=0;
        while(r<nums.size())
        {
            if(nums[r]==0)
            {
                k--;
            }
            while(l<r && k==0)
            {
               if(nums[l]==0)   k++; 
               l++;
            }
            ans = max(ans,r-l);
            r++;
        }
        return ans;
    }
};