class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
      int mod = 1000000007;
      long long ans=0;
      sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
       vector<int> pre = {1};
        for (auto i = 1; i <= nums.size(); ++i)
            pre.push_back((pre.back() << 1) % mod);   
        while(i<=j)
        {
            if(nums[i]+nums[j]>target)  j--;
            else{
                ans= (ans + pre[j-i]) % mod;
                // ans= (ans + (long long)pow(2,j-i)%mod) % mod;
                i++;
            }
        }

      return ans%mod;  
    }
};

