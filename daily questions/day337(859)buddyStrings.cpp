(string s) {
        stack<char> schar;
        stack<int> sind;
        sind.push(-1);
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                schar.push('(');
                sind.push(i);
            }else if(s[i]==')')
            {
                if(schar.empty()) 
                {
                    schar.push(')');
                    sind.push(i);
                }
                else if(schar.top()=='(')
                {
                    schar.pop();
                    sind.pop();
                    ans = max(ans,i-sind.top());
                }else{
                    schar.push(')');
                    sind.push(i);
                }
            }
        }
        return ans;
