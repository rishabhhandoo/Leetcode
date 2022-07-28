class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //using xor
        int elem=0;
        for(int i=0;i<nums.size();i++)
        {
            elem^=nums[i];
        }
        
        return elem;
    }
};