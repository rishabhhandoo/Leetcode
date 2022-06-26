class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0 ; i--)
        {
            if(i==0)
            {
                if(digits[i]==9)
                {digits[i]=0;
                digits.insert(digits.begin(),1);}
                else
                    digits[i]+=1;
                
                return digits;
            }
                

            if(digits[i]==9 && i>0)
            {
                digits[i]=0;
                continue;
            }
            
            
            digits[i] = digits[i]+1;
            return digits;
            
        }
       return digits; 
    }
};