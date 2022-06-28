class Solution {
public:
    
    void helper(vector<int> nums,int index,vector<int> output,vector<vector<int>> &ans){
        //base condition
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        
        //exclude
        helper(nums,index+1,output,ans);
        //include
        output.push_back(nums[index]);
        helper(nums,index+1,output,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        helper(nums,index,output,ans);
        
        return ans;
    }
};