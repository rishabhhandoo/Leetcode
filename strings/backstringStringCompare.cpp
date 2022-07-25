class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> sStack;
        for(char c: s)
        {
            if(c!='#'){
                sStack.push(c);
            }else if(!sStack.empty()){
                 sStack.pop();
            }
        }
        stack <char> tStack;
        for(char c: t)
        {
            if(c!='#'){
                tStack.push(c);
            }else if(!tStack.empty()){
                 tStack.pop();
            }
        }
        
        while(!sStack.empty()){
            char curr = sStack.top();
            sStack.pop();
            if(tStack.empty() || curr!= tStack.top()){
                return false;
            }
            tStack.pop();
        }
        
        return sStack.empty() && tStack.empty();
        
        
        
    }
};