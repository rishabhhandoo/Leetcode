class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;

        for(int i=0;i<piles.size();i++)
        {
            q.push(piles[i]);
        }

        while(k--)
        {
            int ele = q.top();
            q.pop();
            int subs = ele/2;
            ele = ele - subs;
            q.push(ele);
        }
        int ans =0;
        while(!q.empty())
        {
            ans+=q.top();
            q.pop();
        }
        return ans;


    }
};