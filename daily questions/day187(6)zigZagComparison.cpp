class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> arr(numRows, vector<char> (s.size(),'$'));

        int sz=s.size();
        int i=0,j=0,c=0;
        if(numRows==1)  return s;
        while(c<sz)
        {
            //down
            int r=numRows;
            while(r-- && c<sz)
            {
                cout<<s[c];
                arr[i++][j] = s[c++];
            }
            i+=-2;
            j++;
            r=numRows-2;
            while(r-- && c<sz)
            {
                cout<<s[c];
                arr[i--][j++]=s[c++];
            }


            //zig
        }
        string ans="";
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<s.size();j++)
            {
                if(arr[i][j]!='$')
                {
                    ans+=arr[i][j];
                }
            }
        }
        return ans;
    }
};