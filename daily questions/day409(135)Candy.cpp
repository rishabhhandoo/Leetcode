class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        //now we have to insert into it
        for(int i=0;i<n;i++)
        {
            pq.push({a[i],i});
        }
        vector<int> temp(n,0);
        while(!pq.empty())
        {
            int val = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            int l = 0 , r=0;
            if(i-1>=0 && a[i-1]<val)
            {
                l=temp[i-1];
            }
            if(i+1<n && a[i+1]<val)
            {
                r=temp[i+1];
            }
            temp[i] = max(l,r)+1;
        }
        int ans =0;
        for(auto itr:temp) ans+=itr;
        return ans;
    }
};