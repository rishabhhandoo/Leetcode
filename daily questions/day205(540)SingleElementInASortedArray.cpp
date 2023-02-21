class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;


        while(l<=r)
        {
            int mid=l+ (r-l)/2;
            int pos=-1;
            if(mid>0 && nums[mid-1]==nums[mid])
            {
                pos=mid-1;
                
            }else if(mid<nums.size()-1 && nums[mid+1]==nums[mid])
            {
                pos=mid;
            }
            if(pos==-1)
            {
                return nums[mid];
            }else if(pos%2==0)
            {
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return -1;
    }
};