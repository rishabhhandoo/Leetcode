class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0] ;

        for(auto itr:letters)
        {
            if(itr>target)
            {
                return itr;
            }
        }
        return ans;
    }
};