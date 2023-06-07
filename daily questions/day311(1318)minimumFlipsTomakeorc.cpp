
class Solution {
    public:
    int minFlips(int a, int b, int c) {
        if((a|b)==c)
            return 0;
        
        int flips=0;
        
        while(c!=0 || a!=0 || b!=0 ) //compare bits of the numbers as long as atleast one of them is nonzero
        {
            if((c&1)==1)
            {
                if((a&1)==0 && (b&1)==0) //if both are zero while c is 1,one flip is needed
                    flips+=1;
                
            }
            
            else if((c&1)==0)
            {
                if((a&1)==1 && (b&1)==1) //if both are one while c is zero,we need to change both the bits to zero to get the result .So,this requires 2 flips.
                    flips+=2;
                
                else if((a&1)==1 || (b&1)==1) //if one of the bits is one while c is zero,we need to flip it once.
                    flips+=1;
                
            }
            a>>=1; //moving through the bits
            b>>=1;
            c>>=1;
        }
       return flips;
    }
    
    
};