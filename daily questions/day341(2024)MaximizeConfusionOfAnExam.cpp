class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        //approach of O(2n)

        //first for T
        int i=0,j=0;
        int count=k;
        int ans=0;
        int n = s.size();
        while(j<n)
        {
            if(s[j]=='F')   count--;
            while(count<0)  
            {
                if(s[i]=='F')
                {
                    count++;
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        //now considering for false
        i=0,j=0;
        count=k;
        while(j<n)
        {
            if(s[j]=='T')   count--;
            while(count<0)  
            {
                if(s[i]=='T')
                {
                    count++;
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
