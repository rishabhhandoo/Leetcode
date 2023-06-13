class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int>  rows;
        unordered_map<string,int>  cols;

        for(int i=0;i<grid.size();i++)
        {
            string temp="";
            for(int j=0;j<grid.size();j++)
            {
                temp=temp+" "+to_string(grid[i][j]);
            }
            // cout<<temp<<endl;
            rows[temp]++;
        }

        for(int i=0;i<grid.size();i++)
        {
            string temp="";
            for(int j=0;j<grid.size();j++)
            {
                temp=temp+" "+to_string(grid[j][i]);
            }

            // cout<<temp<<endl;
            cols[temp]++;
        }
        int ans=0;
        for(auto itr:rows)
        {
            ans+= cols[itr.first] * itr.second;
        }
        return ans;
    }
};