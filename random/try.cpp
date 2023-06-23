#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int arr[]={1,2,3,7,7,8,9};
    int ind = lower_bound(arr,arr+6,6)-arr;
    cout<<ind<<endl;
return 0;
}