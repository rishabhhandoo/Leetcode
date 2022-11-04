class Solution {
public:
    string reverseVowels(string s) {
        int strt = 0;
        int end = s.size()-1;
        unordered_set<char> uset;
        
        uset.insert('a');
        uset.insert('e');
        uset.insert('i');
        uset.insert('o');
        uset.insert('u');
        
        uset.insert('A');
        uset.insert('E');
        uset.insert('I');
        uset.insert('O');
        uset.insert('U');
        
        while(strt<end)
        {
            while(uset.find(s[strt])==uset.end() && strt<end)
            {
                strt++;
            }
            if(strt>=end)   return s;
            while(uset.find(s[end])==uset.end() && end>strt)
            {
                end--;
            }
            if(strt>=end)   return s;
            char temp=s[strt];
            s[strt]=s[end];
            s[end]=temp;
            strt++;
            end--;
        }
        return s;
    }
};