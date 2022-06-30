class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        vector<int> level;
        level.push_back(1);
        ans.push_back(level);
        for(int i=1;i<numRows;i++)
        {
            level.push_back(1);
            for(int j=1;j<i;j++){
                level[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(level);
        }
        return ans;
    }
};