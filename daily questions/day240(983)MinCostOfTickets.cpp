class Solution {
public:
int dp[366];
    int helper(int curr,vector<int>& days, vector<int>& costs)
    {
        int n = days.size();
        if(curr>=days.size())   return 0;
        if(dp[curr]!=-1)    return dp[curr];
        int day1 = costs[0] + helper(curr+1,days,costs);
        int day7=INT_MAX;
        int day30=INT_MAX;
        int currday=days[curr];
        int i7=currday+7,i30=currday+30;
        //for getting the index of day 7
        int d=curr;
        while(d<n && days[d]<i7)
        {
            d++;
        }

        day7 = costs[1] + helper(d,days,costs);
        //for getting the index of day 30
        d=curr;
        while(d<n && days[d]<i30)
        {
            d++;
        }


        day30 = costs[2] + helper(d,days,costs);
        int temp = min(day1,day7);
        return dp[curr] = min(temp,day30);
    
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return helper(0,days,costs);
    }
};