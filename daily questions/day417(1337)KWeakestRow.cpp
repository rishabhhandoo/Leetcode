class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        int i=0;
        for(auto itr:mat)
        {
            int summ=0;

            for(auto itr1:itr)
            {
                summ+=itr1;
            }
            if(pq.size()<k)  pq.push({summ,i});
            else if(pq.top().first>summ)
            {
                pq.pop();
                pq.push({summ,i});
            }
            i++;
        }
        vector<int> ans(k);
        while(!pq.empty())
        {
            ans[--k] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};