class Solution {
public:
    int strStr(string haystack, string needle) {
        //first ill have to make a lps array
        int n = haystack.size(), m = needle.size();
        if(!n)return 0;
        vector<int> lps(m,0);
        int j(1),i(0);
        lps[0]=0;
        while(j<m)
        {
            if(needle[i]==needle[j])
            {
                lps[j++]=++i;
            }else if(i)
            {
                i=lps[i-1];//lps was ababc now we had ab ab and c messed up so we see where we had ab before and skip there with i
            }else{
                lps[j++]=0;
            }
        }
        //now we move on to do the main process of kmp 
        for (i = 0, j = 0; i < n;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == m) {
                return i - j;
            }
            if (i < n && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
};