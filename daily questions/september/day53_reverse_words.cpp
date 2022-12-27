class Solution {
public:
    
    string reverseWords(string s) {
        string result,word;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                word+=s[i];
            }else{
                reverse(word.begin(),word.end());
                result+=(word);
                result+=" ";
                word.clear();
            }
        }
        reverse(word.begin(),word.end());
        result+=word;
        return result;
    }
};