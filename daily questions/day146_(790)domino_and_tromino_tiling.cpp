class Solution {
public:
    int numTilings(int n) {
        vector<long long int> ans (1001,0);
        ans[0]=0;
        ans[1]=1;
        ans[2]=2;
        ans[3]=5;

        if(n<=3)    return ans[n];
        int md = 1e9;
        md+=7; 
        for(int i=4;i<=n;i++)
        {
            ans[i]=ans[i-1]*2 + ans[i-3];
            ans[i]=ans[i]%md;
        }

        return ans[n];


    }
};