class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        //prefix arrays

        vector<vector<int>> ans(n,vector<int> (n,0));
        for(auto itr : queries)
        {
            int r1=itr[0];
            int c1=itr[1];
            int r2=itr[2];
            int c2=itr[3]+1;

            for(int i=r1;i<=r2;i++)
            {
                ans[i][c1]++;
            }
            if(c2<n)
            {
                for(int i=r1;i<=r2;i++)
                {
                    ans[i][c2]--;
                }
            }

        }
        //traversing over the matrix
        for(int i=0;i<n;i++)
        {
            int curr=0;
            for(int j=0;j<n;j++)
            {
                ans[i][j]=ans[i][j]+curr;
                curr=ans[i][j];
            }
        }
        return ans;
    }
};