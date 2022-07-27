class Solution {
public:
    vector<string> ans;
    
    void helper(string p,string up,int index){
        if(index>=up.size()){
            ans.push_back(p);
            return;
        }
        
        
        //if upper case or lower
        if((up[index] >=65 && up[index]<=90) || (up[index] >=97 && up[index]<=122))
        {
            //upper case
            if(up[index] >=65 && up[index]<=90){
                
                char val = up[index];
                p.push_back(val);
                helper(p,up,index+1);
                p.pop_back();
                
                val = up[index] + 32;
                p.push_back(val);
                helper(p,up,index+1);
                p.pop_back();
            }
            //lowercase
            if(up[index] >=97 && up[index]<=122){
                
                char val = up[index];
                p.push_back(val);
                helper(p,up,index+1);
                p.pop_back();
                
                val = up[index] - 32;
                p.push_back(val);
                helper(p,up,index+1);
                p.pop_back();
            }
            
        }else{
            p.push_back(up[index]);
           helper(p,up,index+1); 
        }        
    }
    
    vector<string> letterCasePermutation(string s) {
        
        string p="";
        int index=0;
        
        helper(p,s,index);
        
        return ans;
        
        
    }
};