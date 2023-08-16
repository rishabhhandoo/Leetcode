class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && dq.back()<nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
            if(i>=k-1)
            {
                ans.push_back(dq.front());
                if(nums[i-k+1]==dq.front()) dq.pop_front();
            }
        }
        return ans;
    }
};