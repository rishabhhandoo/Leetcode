class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int steps[n+1];
        steps[0]=0;
        steps[1]=0;
        
        for(int i=2;i<n+1;i++)
        {
            steps[i]=min(steps[i-1]+cost[i-1],steps[i-2]+cost[i-2]);
        }
        
        return steps[n];
    }
};