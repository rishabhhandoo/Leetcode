class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //we will be using binary search for this question
        sort(potions.begin(),potions.end());
        vector<int> ans(spells.size());
        //now we have to apply binary search
        for(int i=0;i<spells.size();i++)
        {
            int l=0;
            int r=potions.size()-1;
            int ind=0;
            while(l<=r)
            {
                int mid= l+(r-l)/2;

                if((long long)spells[i]*(long long)potions[mid] < success)
                {
                    l=mid+1;
                }else if((long long)spells[i]*(long long)potions[mid] >= success)
                {
                    r=mid-1;
                }

                ind = potions.size()-l;
                ans[i]=ind;
            }
        }
        return ans;
    }
};