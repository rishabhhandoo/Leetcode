class Solution {
public:
    string makeGood(string s) {
        stack<int> st;
        if(s.size()==0 || s.size()==1) return s;
        st.push(s[0]);
        
        for(int i=1;i<s.size();i++)
        {
            if(!st.empty() && (st.top() == s[i]-32 || st.top() == s[i]+32))
            {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans; 
    }
};