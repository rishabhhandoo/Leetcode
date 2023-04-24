class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i=0;i<n;i++)
        {
            pq.push(stones[i]);
        }
        while(pq.size()>1)
        {
            int larger = pq.top();
            pq.pop();
            int smaller = pq.top();
            pq.pop();

            if(larger!=smaller)
            {
                larger = larger - smaller;
                pq.push(larger);
            }
        }
        return pq.size()==0?0:pq.top();
    }
};