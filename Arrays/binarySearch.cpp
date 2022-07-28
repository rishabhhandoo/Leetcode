class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l=0;
        int r=nums.size()-1;
        
        if(nums[0]==target) return 0;
        int pivot;
        if(nums[0]>nums[nums.size()-1]){
            //find pivot
                while(l<r){

                int mid=l + (r-l)/2;

                if(nums[mid]>nums[mid+1]){
                    pivot = mid;
                    break;
                }else if(nums[mid]<nums[mid+1]){
                    if(nums[mid]>nums[nums.size()-1]){
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                  }
                }
            
             //binary search for left
        l=0;
        r=pivot;
        while(l<r){
            int mid = l + (r-l)/2;
            
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                r=mid-1;
            }else l = mid+1;
        }        
        //binary search for right
        l=pivot;
        r=nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                r=mid-1;
            }else l = mid+1;
        }    
            
        }
        else{
        l=0;
        r=nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                r=mid-1;
            }else l = mid+1;
        } 
            
        }
        
        
        
         
    return -1;
    }
};