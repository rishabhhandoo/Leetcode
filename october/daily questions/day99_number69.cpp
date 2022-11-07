class Solution {
public:
    int maximum69Number (int num) {
        string number="";
        int pos =0;
        int change =0;
        while(num>0)
        {
            char add = '0' + num%10;
            num=num/10;
            number += add;
        }
         reverse(number.begin(),number.end());
        for(int i=0;i<number.size();i++)
        {
            if(number[i]=='6')
            {
                number[i]='9';
                break;
            }
        }
       
        return stoi(number);
    }
};