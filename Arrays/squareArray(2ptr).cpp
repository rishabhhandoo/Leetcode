class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int k=j;
        vector<int> ans(nums.size());
        
        while(i<=j){
            if(abs(nums[i]) >= abs(nums[j])){
                ans[k]=pow(nums[i],2);
                k--;
                i++;
            }else{
                ans[k]=pow(nums[j],2);
                k--;
                j--;
            }
        }
        return ans;
    }
};