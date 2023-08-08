class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int l=0;
        int r=n-1;
        int piv=n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(mid+1<n && nums[mid]>nums[mid+1])
            {
               piv=mid; 
               break;
            }
            else if(nums[mid]<nums[l])
            {
                r=mid-1;
            }else
            {
                l=mid+1;
            }
        }
        //right side
        if(nums[0]>target)
        {
            l=piv+1;
            r=n-1;
            while(l<=r)
            {
                int mid = l + (r-l)/2;
                if(nums[mid]==target)
                {
                    return mid;
                }else if(nums[mid]>target)
                {
                    r=mid-1;
                }else   l=mid+1;
            }
        }else{
            l=0;
            r=piv;
            while(l<=r)
            {
                int mid = l + (r-l)/2;
                if(nums[mid]==target)
                {
                    return mid;
                }else if(nums[mid]>target)
                {
                    r=mid-1;
                }else   l=mid+1;
            }
        }
        return -1;
    }
};