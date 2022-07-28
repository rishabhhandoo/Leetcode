class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r=nums.size()-1;
        
        if(nums.size()==0){
            return {-1,-1};
        }
        
        //for left most
        while(l<r){
            int mid = (r+l)/2;
            
            if(nums[mid]>target){
                r=mid-1;
            }else if(nums[mid]<target){
                l=mid+1;
            }else {
                r=mid;
            }
        }
        int ind1 = l;
        
        if(nums[l]!= target){
            return {-1,-1};
        }
        
        r=nums.size()-1;
        while(l<r){
            int mid =(r+l)/2 +1;
            if(nums[mid]<target){
                l=mid+1;
            }else if(nums[mid]>target){
                r=mid-1;
            }else {
                l=mid;
            }
        }
        
        int ind2=r;
        
        vector<int> pair{ind1,ind2};
        return pair;
        
    }
};