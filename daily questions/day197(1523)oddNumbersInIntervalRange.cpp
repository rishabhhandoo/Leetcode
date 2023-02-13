
class Solution {
public:
    int countOdds(int low, int high) {
        //if size odd then we have n/2+1
        int range = high-low+1;

        if(range%2==0)
        {
            return range/2;
        }else   return (low%2==0)?range/2:range/2+1;
    }
};