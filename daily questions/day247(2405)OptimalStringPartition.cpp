class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        vector<string> ans;
        vector<bool> vis(27,0);
        string curr="";
        for(int i=0;i<n;i++)
        {
            string temp=curr;
            curr+=s[i];
            if(vis[s[i]-'a']!=true)
            {
                vis[s[i]-'a']=true;
            }else{
                ans.push_back(temp);
                curr=s[i];
                for(auto itr:temp)  vis[itr-'a']=false;
                vis[s[i]-'a']=true;
            }
        }
            for(auto itr:vis){
                if(itr==true)
                {
                    ans.push_back(curr);
                    break;
                }
            }
        return ans.size();
    }
};