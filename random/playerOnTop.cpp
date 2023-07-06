#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
int helper(int n,int m,vector<vector<int> > arr)
{
    vector<int> wins(n,0);
    for(int i=0;i<m;i++)
    {
        int maxx=0;
        for(int j=0;j<n;j++)
        {
            maxx=max(maxx,arr[j][i]);
        }
        for(int j=0;j<n;j++)
        {
            if(arr[j][i]==maxx)
            {
                wins[j]++;
            }
        }
    }
    int maxx=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(maxx<wins[i])
        {
            maxx=wins[i];
            ans=i+1;
        }
    }
    return ans;
}
int main()
{
    const int n = 3;
    const int m = 4;
    vector<vector<int> > arr;
    vector<int> row1{1, 3, 4, 5};
    vector<int> row2{7, 2, 3, 4};
    vector<int> row3{1, 3, 2, 1};
    
    arr.push_back(row1);
    arr.push_back(row2);
    arr.push_back(row3);
    cout<<helper(n,m,arr);

return 0;
}