class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        int sum=0;
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        
        for(int i=0;i<nums.size();i++)
        {
            sum=nums[i];
            
            int l=i+1;
            int r = nums.size()-1;
            
            while(l<r)
            {
                int temp=sum+nums[l]+nums[r];
                if(abs(target-temp) <= abs(target-ans) )
                {
                    ans = temp;
                }
                if(temp>target)
                {
                    r--;
                }
                else if(temp<target)
                {
                    l++;
                }
                else
                {
                    return temp;
                }
                    
            }
        }
        return ans;
    }
};