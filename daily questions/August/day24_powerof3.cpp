class Solution {
public:
    bool isPowerOfThree(int n) {
        int power=0;
        
        while(pow(3,power)<n)
        {
            power++;
        }
        if(pow(3,power) == n)  return true;
         else  return false;
    }
};