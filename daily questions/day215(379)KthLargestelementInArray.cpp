class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int> ,greater<int>> pq;

        for(auto itr:nums)
        {
            if(pq.size()<k)
            {
                pq.push(itr);
            }else{
                if(itr>pq.top())
                {
                    pq.pop();
                    pq.push(itr);
                }
            }
        }
        return pq.top();
    }
};