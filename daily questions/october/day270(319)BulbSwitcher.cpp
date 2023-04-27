class Solution {
public:
    bool issq(int x)
    {
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    int bulbSwitch(int n) {
        //just find the prime numbers
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(issq(i)) ans++;
            
        }
        return ans;
    }
};