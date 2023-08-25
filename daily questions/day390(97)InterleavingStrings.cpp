class Solution {
public:
    int dp[101][101][201];

    bool helper(string &s1, string &s2, string &s3,int i,int j,int k,int n1,int n2,int n3)
    {
        if(i==n1 && j==n2 && k==n3)   return true;
        else if((i==n1 && j==n2) || (k==n3)) return false;
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        bool val = false;
        if(i<n1 && s1[i]==s3[k])    val = val || helper(s1,s2,s3,i+1,j,k+1,n1,n2,n3);
        if(j<n2 && s2[j]==s3[k])    val = val || helper(s1,s2,s3,i,j+1,k+1,n1,n2,n3);
        return dp[i][j][k]= val;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        int i=0,j=0,k=0;
        int n1= s1.size();
        int n2=s2.size();
        int n3=s3.size();
        return helper(s1,s2,s3,i,j,k,n1,n2,n3);
    }
};