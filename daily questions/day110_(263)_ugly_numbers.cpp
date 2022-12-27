class Solution {
public:
    bool isUgly(int n) {
        if(n==0)    return false;
        if(n==1) return true;
        if(n<0) return false;
        // for(int i=2;i<=n;i++)
        // {
        //     cout<<i<<endl;
        //     if(i%2!=0 && i%3!=0 && i%5!=0)
        //     {
        //         if(n%i==0)
        //         {
        //             return false;
        //         }
        //     }
        // }
        
        while(n%2==0)n=n/2;
        while(n%3==0)n=n/3;
        while(n%5==0)n=n/5;
        
        return n==1;
        
    }
};