#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int Size[N];

multiset<int> sizes;
void make(int v) {
    parent[v] = v;
    Size[v] = 1;
    sizes.insert(1);
}

int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
void merge(int a,int b )
{

    sizes.erase(sizes.find(Size[a]));
    sizes.erase(sizes.find(Size[b]));
    sizes.insert(Size[a]+Size[b]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b) {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        merge(a,b);
        Size[a] += Size[b];
    }
}


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)   make(i);
    int q;
    cin>>q; //number of takeovers

    while(q--)
    {
        int i,j;
        cin>>i>>j;
        Union(i,j);
        if(sizes.size()>1)
        {
            int mini = *(sizes.begin());
            int maxi = *(--sizes.end());

            cout<<maxi-mini<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    
return 0;
}