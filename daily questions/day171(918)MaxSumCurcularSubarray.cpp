class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        int currMin=0;
        int currMax=0;
        int summ=0;
        for(int i=0;i<nums.size();i++)
        {
            summ+=nums[i];
            currMax+=nums[i];
            if(currMax>maxSum)  maxSum=currMax;
            if(currMax<0)  currMax=0;

            currMin+=nums[i];
            if(currMin<minSum)  minSum = currMin;
            if(currMin>0)   currMin=0;
           
        }
        if(minSum==summ)
        {
            return maxSum;
        }
        cout<<summ<<" "<<minSum<<endl;
        return max(maxSum,summ-(minSum));
    }
};