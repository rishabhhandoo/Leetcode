class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long i=0;
        while(i<nums.size())
        {
            int j=i;
            while(j<nums.size() && nums[j]==0)
            {
                j++;
                ans+=j-i;
            }
            if(j==i)    i++;
            else
                i=j;
        }
        return ans;
    }
};s