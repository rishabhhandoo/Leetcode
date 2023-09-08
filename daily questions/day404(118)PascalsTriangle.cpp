class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows>=1)  ans.push_back({1});
        if(numRows>=2)  ans.push_back({1,1});
        
        for(int i=3;i<=numRows;i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j< (i-1) ; j++)
            {
                int sum = ans[i-2][j] + ans[i-2][j-1];
                temp.push_back(sum);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};