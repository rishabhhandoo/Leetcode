class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n,0);
        bool flag=false;
        int x=0,y=n;
        for(int i=0;i<2*n;i++)
        {
            if(!flag)
            {
                ans[i]=nums[x++];
            }else{
                ans[i]=nums[y++];
            }
            flag=!flag;

        }
    return ans;
    }
};