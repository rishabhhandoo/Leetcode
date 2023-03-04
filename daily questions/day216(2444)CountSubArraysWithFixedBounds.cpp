class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans=0;
        int minStart=0;
        int maxStart=0;
        int start=0;
        bool minF=0,maxF=0;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            if(num>maxK || num<minK)
            {
                start=i+1;
                minF=0;
                maxF=0;
            }
            if(num==minK)
            {
                minStart=i;
                minF=true;
            }
            if(num==maxK)
            {
                maxStart=i;
                maxF=true;
            }

            if(maxF && minF)
            {
                ans+= (min(minStart,maxStart) - start +1);
            }
        }
        return ans;
    }
};
