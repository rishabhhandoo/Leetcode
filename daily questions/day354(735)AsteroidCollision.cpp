class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(a[i]>0)
            {
                s.push(a[i]);
            }
            else
            {
                bool check = true;
                if(!s.empty() && s.top()<0) 
                {
                    check = false;
                    s.push(a[i]);
                }
                else if(!s.empty() && s.top()==abs(a[i]))   
                {
                    s.pop();
                    check = false;
                }
                if(check)
                    while(!s.empty() && s.top()>0 && s.top()< abs(a[i]))
                    {
                        s.pop();
                    }
                if((s.empty()||s.top()<0) && check )   s.push(a[i]);
                else if(!s.empty() && s.top()==abs(a[i]) && check)   s.pop();
            }
        }
        //now we have a stack
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};