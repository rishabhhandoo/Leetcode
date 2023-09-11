class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        map<int,vector<int>> umap;
        int n =a.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            umap[a[i]].push_back(i);
        }
        for(auto itr:umap)
        {
            vector<int> temp;
            int c=0;
            for(auto itr1:itr.second)
            {
                c++;
                temp.push_back(itr1);
                if(c%itr.first==0)
                {

                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};