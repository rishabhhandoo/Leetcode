class Solution {
public:
    int ans = INT_MIN;
    void helper(int m,vector<vector<int>>& requests,vector<int> &vis,int c)
    {
        if(m<0)
        {
            //now we will see if we have c
            int check =0;
            for(auto itr:vis)   if(itr!=0)  return;
            if(check ==0)ans = max(ans,c);
            return;
        }
        //take and not take
        helper(m-1,requests,vis,c);
        int from =requests[m][0];
        int to =requests[m][1];
        vis[from]++;
        vis[to]--;
        helper(m-1,requests,vis,c+1);
        vis[from]--;
        vis[to]++;
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> vis(n,0);
        int m = requests.size();
        helper(m-1,requests,vis,0);
        return ans;
    }
};