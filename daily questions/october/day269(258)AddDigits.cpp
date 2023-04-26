class Solution {
public:
    int addDigits(int num) {
        // if(num<=10 && num!=0)     return 1;

        int ans=0;
        while(num/10>0)
        {
            int temp = num;
            int summ=0;
            while(temp)
            {
                summ+=temp%10;
                temp = temp/10;
            }
            num=summ;
            ans++;
        }
        return num;
    }
};