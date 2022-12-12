class Solution {
public:
    int climbStairs(int n) {
        int ways =0;
        int prev1=1;
        int prev2=1;
        if(n==0)    return 0;
        if(n<2) return 1;
        for(int i=1;i<n;i++)
        {
            ways = prev1 + prev2;
            prev2 = prev1;
            prev1 = ways;
        }
        return ways;
        
    }
};