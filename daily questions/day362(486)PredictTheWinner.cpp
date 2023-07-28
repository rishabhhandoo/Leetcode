class Solution {
public:
    bool helper(int summ1,int summ2,int i,int j,int p1,vector<int>& nums)
    {
        if(i>j) return summ1>=summ2;
        
        if(p1) { 
            return helper(summ1 + nums[i],summ2 , i+1,j,0,nums) || helper(summ1 + nums[j],summ2,i,j-1,0,nums);
    
        }else{
        return helper(summ1 ,summ2 + nums[i], i+1,j,1,nums) && helper(summ1 ,summ2 + nums[j], i,j-1,1,nums);
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return helper(0,0,0,n-1,1,nums);
    }
};