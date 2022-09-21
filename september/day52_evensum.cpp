class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int evensum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
                evensum+=nums[i];
        }
        
        
        for(int i=0;i<queries.size();i++)
        {
            int ind = queries[i][1];
            if(nums[ind]%2==0)
            {
                nums[ind]+=queries[i][0];
                if(nums[ind]%2==0)
                {
                    evensum+=queries[i][0];
                }else{
                    evensum-=(nums[ind]-queries[i][0]);
                }
            }else{
                nums[ind]+=queries[i][0];
                if(nums[ind]%2==0)
                {
                    evensum+=nums[ind];
                }                
            }
            
            ans.push_back(evensum);
        }
    return ans;
    }
};