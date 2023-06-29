#include<iostream>
using namespace std;
 
int main()
{
string s= "hello";

s.insert('(',s.begin()+1);
cout<<s<<endl;

return 0;
}

