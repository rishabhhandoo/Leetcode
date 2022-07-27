class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    
    
    void helper(vector<int> &p,vector<int> &up,int index){
       
//         cout<<index<<" "<<endl;
//         for(auto i:p){
//         // cout<<"processed "<<i<< " ";
            
//         }
        if(index<0)
        {
            
            if(s.find(p) == s.end())
            {
                s.insert(p);
                ans.push_back(p);
            }
            // cout<<"hello"<<" ";
            return;
        }
        
        
        //not take;
        helper(p,up,index-1);
        //take
        p.push_back(up[index]);
        helper(p,up,index-1);
        p.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> p;
        int index = nums.size()-1;
        helper(p,nums,index);
        
        return ans;
    }
};