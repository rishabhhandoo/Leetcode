class Solution {
public:
    void helper(int i,int n,int k , vector<int> &curr,vector<vector<int>> &ans)
    {
        // for(auto itr:curr  )    cout<<itr<<" ";
        // cout<<endl;
        if(k==0){
            ans.push_back(curr);
            return;
        }
        if(i>n) return;
        for(int j=i;j<=n;j++)
        {
            
            curr.push_back(j);
            helper(j+1,n,k-1,curr,ans);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
       vector<int> curr;
       vector<vector<int>> ans;
       helper(1,n,k,curr,ans); 
       return ans;
    }
};