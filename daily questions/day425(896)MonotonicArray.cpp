class Solution {
    public boolean isMonotonic(int[] nums) {
        if(nums.length<=1)  return true;
        int n=nums.length;
        boolean isIncreasing = (nums[0]-nums[n-1]>0)? false : true;
        for(int i=0;i<n-1;i++)
        {
            if(isIncreasing && nums[i+1]<nums[i])   return false;
            else if(!isIncreasing && nums[n-i-2] < nums[n-i-1]) return false;
        }
        return true;

    }
}