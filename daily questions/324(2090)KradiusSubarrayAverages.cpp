class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n=nums.size();
        vector<int> ans(n,-1);
        long long int div = 2*k+1;
        if(div>n)   return ans;
        long long int summ=0;
        long long int mid=0;
        long long int r=0;
        while(mid<k)
        {
            summ+=nums[mid++];
        }
        //okay so first 3 done till 0.1.2. 3  4.5.6
        r=mid;
        while(r<n)
        {
            summ+=nums[r];
            if(r>=mid+k)
            {
                ans[mid]=summ/div;
                summ-=nums[mid-k];
                mid++;
            }
            r++;
        }
        return ans;
    }
};