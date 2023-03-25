#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int num;
    cout<<"Enter the amount of numers you want to sum ";
    cin>>num;
    int sum=0;
    cout<<"Start entering the numbers"<<endl;
    while(num--)
    {
        int a;
        cin>>a;
        sum+=a;
    }
    cout<<"Sum = "<<sum<<endl;
return 0;
}