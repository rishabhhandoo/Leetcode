class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
    long long summ=0;      
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
        summ+=nums[i];
        int temp = ceil(double(summ)/(i+1));
        ans = max(ans,temp);
    }
    return ans;
    }
    
};