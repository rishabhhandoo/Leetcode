class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int n = path.size();
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='.')
            {
                if(i+1<n && path[i+1]!='/')
                {
                    string temp ="";
                    while(i<n && path[i]!='/')
                    {
                        temp+=path[i++];
                    }
                    cout<<temp<<endl;
                    reverse(temp.begin(),temp.end());
                    if(temp=="..")
                    {
                        if(!s.empty())  s.pop();
                    }else{
                        s.push(temp);
                    }
                }
            }else if(path[i]!='/'){
                // int temp = i;
                // while(path[i]!='/')
                // {
                //     i++;
                // }
                // string temp1 = path.substr(temp,i-temp);
                // cout<<temp1;
                string temp1="";
                while(i<n && path[i]!='/')
                {
                    temp1+=path[i++];
                }
                reverse(temp1.begin(),temp1.end());
                s.push(temp1);
            }
        }
        string ans="";
        if(s.empty())   ans="/";
        while(!s.empty())
        {
            ans+=s.top();
            ans+="/";
            s.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};