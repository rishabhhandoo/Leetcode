class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans =0;
        
        for(int itr =0;itr<strs[0].size();itr++)
        {
            string curr="";
            for(int i=0;i<strs.size();i++)
            {
                curr+=strs[i][itr];
            }
            string srted=curr;
            sort(srted.begin(),srted.end());
            if(srted!=curr) ans++;
        }
        return ans;
    }
};