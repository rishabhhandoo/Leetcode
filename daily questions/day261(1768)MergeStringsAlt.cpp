class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int i=0,j=0;
        int n1=w1.size(),n2=w2.size();
        bool flag = true;
        string ans ="";
        while(i<n1 && j<n2)
        {
            if(flag)
            {
                ans+=w1[i++];
                flag=!flag;
            }else{
                ans+=w2[j++];
                flag=!flag;
            }
        }
        while(i<n1)
        {
            ans+=w1[i++];
        }
        while(j<n2)
        {
            ans+=w2[j++];
        }
        return ans;
    }
};