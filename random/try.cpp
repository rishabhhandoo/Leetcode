
// #include <bits/stdc++.h>

// using namespace std;
// int helper(unordered_map<int,int>&mp,int i,int k ,int mask,int n)
// {
//     //if(mask== (1<<k)-1) return 1;
//     if(i>=n+1)
//     {
//         cout<<"mask : "<<mask<<endl;
//         if(mask== (1<<k)-1)return 1;
//         return 0;
//     }
//     int val=0;
//     int newmask = (mask|mp[i]);
//     val += helper(mp,i+1,k,mask,n);
//     val += helper(mp,i+1,k,newmask,n);
//     //not take
    
//     return val;
// }
// int main()
// {
//     int n,k;
//     cin>>n>>k;
//     unordered_map<int,int>mp;
//     for(int i=0;i<n;i++)
//     {
//         int colors;
//         cin>>colors;
//         int cno=0;
//         while(colors--)
//         {
//             int val;
//             cin>>val;
//             cno=cno| (1<<(val-1));
//         }
//         cout<<"cno "<<cno<<endl;
//         mp[i+1]=cno;
//     }
//     int ans=helper(mp,1,k,0,n);
//     cout<<ans;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int dp[105][105][1 << 11]; // dp[i][j][mask] represents the number of ways to choose j colors for the first i pen types using colors represented by mask

int helper(unordered_map<int,int>& mp, int i, int k, int mask, int n)
{
    if (i > n)
    {
        if (mask == (1 << k) - 1)
            return 1;
        return 0;
    }
    
    if (dp[i][k][mask] != -1)
        return dp[i][k][mask];
    
    int val = 0;
    int newmask = (mask | mp[i]);
    
    val += helper(mp, i + 1, k, mask, n);     // not choosing colors from the i-th pen type
    val += helper(mp, i + 1, k, newmask, n);  // choosing colors from the i-th pen type
    
    return dp[i][k][mask] = val;
}

int main()
{
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    
    for (int i = 0; i < n; i++)
    {
        int colors;
        cin >> colors;
        int cno = 0;
        while (colors--)
        {
            int val;
            cin >> val;
            cno |= (1 << (val - 1));
        }
        mp[i + 1] = cno;
    }
    
    memset(dp, -1, sizeof(dp));  // Initializing the dp array with -1
    
    int ans = helper(mp, 1, k, 0, n);
    cout << ans;
    
    return 0;
}
