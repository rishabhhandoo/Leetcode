class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        int n = interval.size();
        vector<vector<int>> ans;
        int strt=newInterval[0];
        int end=newInterval[1];
        bool flag = true;
        if(n==0) 
        {
            ans.push_back(newInterval);
            flag = false;
        }    
        int i=0;
        for(i;i<n;i++)
        {
            int si=interval[i][0];
            int ei=interval[i][1];
            
            //full overlap
            if(si<=strt && end<=ei)
            {
                ans.push_back(interval[i]);
                flag = false;

                break;
            }
            //no overlap
            else if( ei<strt)
            {
                vector<int> temp;
                temp.push_back(si);
                temp.push_back(ei);

                ans.push_back(temp);
            }else if(end<si)
            {
                vector<int> temp1;
                temp1.push_back(strt);
                temp1.push_back(end);
                ans.push_back(temp1);
                for(i;i<n;i++)
                {
                    ans.push_back(interval[i]);
                }
                flag = false;
                break;
            }


            //overlap
            else if(strt<=interval[i][0] && end<=interval[i][1] && end>=interval[i][0])
            {
                end=interval[i][1];
            }else if(si<=strt && strt<=ei)
            {
                strt=si;
                end=max(ei,end);
            }else if(strt<=si && end>=ei)
            {
                continue;
            }
        }
            vector<int> temp;
            temp.push_back(strt);
            temp.push_back(end);
            if(flag) ans.push_back(temp);
            
            for(i=i+1;i<n;i++)
            {
                ans.push_back(interval[i]);
            }
            return ans;
    }
};