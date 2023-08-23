#include<bits/stdc++.h>
using namespace std;



// int helper3(int i, string &num ,int summ,unordered_map<char,int> umap)
// {
//     if(i>=num.size())
//     {
//         if(summ==0) return 1;
//         else return 0;
//     }
//     if(summ<0)  return 0;
//     int val=0;
//     if(umap.find(num[i]) != umap.end())
//     {
//         int add = umap[num[i]];
//         val += helper(i+1,num,summ+add,umap);
//     }else{
//         //) or (
//         umap[num[i]]=1;
//         val += helper(i+1,num,summ+1,umap);
//         umap[num[i]]=-1;
//         val+=helper(i+1,num,summ-1,umap);
//     }
//     return val;
// }
int helper4(int a[])
{

    int n = a[6];
    vector<int> f(n+1,1);
    vector<int> g(n+1,1);
    vector<int> h(n+1,1);
    for(int i=2;i<n+1;i++)
    {
        f[i]=a[0]*f[i-1] + a[1]*g[i-2];
        g[i]=a[2]*g[i-1] + a[3]*h[i-2];
        f[i]=a[4]*h[i-1] + a[5]*f[i-2];
    }
    return f[n];
}
int main()
{
    // string num = "1234";
    // int n = 8;
    // unordered_map<char,int> umap;
    // cout<<helper(0,num,0,umap)<<endl;
   int a[] = {5,6,3,7,1,2,5};
    cout<<helper4(a);
return 0;
}