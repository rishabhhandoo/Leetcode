class Solution {
public:
    int arraySign(vector<int>& nums) {
        int counter=0;

        for(auto itr: nums)
        {
            if(itr==0)  return 0;
            else if(itr <0) counter++;
        }
        return counter%2==0?1:-1; 
    }
};