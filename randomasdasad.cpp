#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int i,j,k,c;
    for(i = 1; i < 31; i++)
        for(j = 1; j < 31; j++)
            for(k = 1; k < 31; k++)
                    if((i+j+k) % 3 ==0)
                    {
                        c++;
                    }
    cout<<c<<endl;
return 0;
}