class Solution {
public:
    void helper(int i, string &s,vector<string> &ans,string &curr,map<char,vector<char>> &umap)
    {
        int n=s.size();
        if(i==n)
        {
            ans.push_back(curr);
            return;
        }
        //base case
        char digit = s[i];
        for(auto itr:umap[digit])
        {
            curr.push_back(itr);
            helper(i+1,s,ans,curr,umap);
            curr.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> umap;
        umap['2']={'a','b','c'};
        umap['3']={'d','e','f'};
        umap['4']={'g','h','i'};
        umap['5']={'j','k','l'};
        umap['6']={'m','n','o'};
        umap['7']={'p','q','r','s'};
        umap['8']={'t','u','v'};
        umap['9']={'w','x','y','z'};
        vector<string> ans;
        string curr;
        if(digits.size()==0)    return ans;
        helper(0,digits,ans,curr,umap);
        return ans;
    }
};