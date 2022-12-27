class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int strt=0;
        int end=strt+1;
        
        if(nums.size()==0)
        {
            return 0;
        }
        
        if(nums.size()==1)
        {
            return 1;
        }
        
        while(end<nums.size())
        {
            if(nums[strt] == nums[end])
            {
                end++;
            }
            else
            {
                strt++;
                nums[strt]=nums[end];
                end++;    
            }
        }
        return strt+1;
    }
};