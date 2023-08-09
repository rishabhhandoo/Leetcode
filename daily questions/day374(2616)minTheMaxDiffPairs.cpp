class Solution {
public:
    bool isPossible(vector<int>& nums, int p,int diff)
    {
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if( abs(nums[i]-nums[i-1]) <=diff )
            {
                i++;
                p--;
            }
        }
        if(p<=0)    return true;
        else    return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums[n-1] - nums[0];

        while(l<r)
        {
            int mid = l + (r-l)/2;
            if(isPossible(nums,p,mid))
            {
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};