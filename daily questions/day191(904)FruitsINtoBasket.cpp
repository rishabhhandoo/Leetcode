class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;

        if(fruits.size()==1)    return 1;
        int i=0,j=0;
        int n = fruits.size();
        int ans =0;
        int counter=0;
        while(j<n)
        {
            map[fruits[j]]++;
            counter++;

            if(map.size()<2)
            {
                ans = max(counter,ans);
                j++;
            }else{
                while(map.size()>2)
                {
                    map[fruits[i]]--;
                    counter--;
                    if(map[fruits[i]]==0)
                    {
                        map.erase(fruits[i]);
                    }
                    i++;
                }
                if(map.size()==2)
                {
                    ans = max(counter,ans);
                }
                j++;
            }
        }
        return ans;
    }
};