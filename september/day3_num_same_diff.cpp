class Solution {
public:
    set<int> s;
    void helper(int ind,string p,vector<int> &ans,int k,int n)
    {
        //base case
        if(ind==n)
        {   
            int val = stoi(p);
            if(s.find(val)==s.end())
            {
                ans.push_back(val);
                s.insert(val);
            }
            return;
        }
        //base work
        if(p[ind] > '9' || p[ind]<'0')
        {
            return;
        }
        
        char abhi = p[ind];
        p[ind+1]= abhi + k ;
        helper(ind+1,p,ans,k,n);
        p[ind+1]=abhi-k;
        helper(ind+1,p,ans,k,n);  
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
        int index=0;
        string p="";
        
        for(int i=0;i<n;i++)
        {
            p+="0";
        }
        // cout<<p;
        for(int i=1;i<10;i++)
        {
            char abhi = i +'0';
            p[index]= abhi;
            // cout<<p[index];
            helper(index,p,ans,k,n);
        }
      
        
        return ans;
        
    }
};