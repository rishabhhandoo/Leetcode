#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<int> a;
    for(int i=0;i<5;i++)
    {
        a.push_back(i);
    }
    int maxx = INT_MIN;
    for(int i=0;i<a.size();i++)
    {
        if((a[i]&maxx) > maxx)  maxx=a[i];    
    }
    cout<<maxx;
return 0;
}