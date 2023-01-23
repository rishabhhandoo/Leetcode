class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> judge_trust(n,0);
        vector<int> judge(n,0);
        cout<<n<<endl;
        for(int i=0;i<trust.size();i++)
        {
            judge_trust[trust[i][0] -1] = 1; 
            judge[trust[i][1]-1]=judge[trust[i][1]-1]+1;
           cout<<"i: "<<i<<endl; 
        }

        for(int i=0;i<n;i++)
        {cout<<"i: "<<i<<endl;
            if(judge_trust[i]==0)
            {
                if(judge[i]==n-1)
                {
                    return i+1;
                }
            }
        }
        return -1;
    }
};