class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
       
        int pre[n];
        int maxP=0;
        
        int suf[n];
        int maxS=0;
        
        int sum=0;
        
        // pre[0]=0;
        // suf[n-1]=0; if u consider them 0 then ull neglect the edge pillars
        
        for(int i=0;i<n;i++)
        {
            maxP = max(maxP,height[i]);
            pre[i]=maxP;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            maxS = max(maxS,height[i]);
            suf[i]=maxS;
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<"Pre :"<<pre[i]<<" Post: "<<suf[i]<<endl;
        // }
        for(int i=0;i<n;i++)
        {
            sum+=min(pre[i],suf[i])-height[i];
        }
        
        return sum;
    }
};