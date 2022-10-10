class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1)    return "";
        int n=s.size();
        int l=0;
        int r=n-1;
        int change;
        int flag=1;
        while(l<r)
        {
            if(s[l]!='a')
            {
                s[l]='a';
                return s;
            }else{
                if(flag)
                {
                    change=r;
                    cout<<change<<endl;
                    flag=0;
                }
                
                l++;
                r--;
            }
        }
        cout<<change<<endl;
        s[change]='b';
        return s;
    }
};