#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int Size[N];

void make(int v) {
    parent[v] = v;
    Size[v] = 1;
}

int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    // if (a != b) {
    //     if (Size[a] < Size[b])
    //         swap(a, b);
        parent[a] = b;
        Size[b] += Size[a];
}

void makeBoss(int a)
{
    int parenta = find(a);
    parent[parenta]=a;
    parent[a]=a;
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
        
        int type;
        cin>>type;
        if(type==1)
        {
            int a,b;
            cin>>a>>b;
            Union(a,b);
        }else if(type==2)
        {
            int a;
            cin>>a;
            makeBoss(a);
        }else{
            int a;
            cin>>a;
            cout<<find(a)<<endl;
        }
    }
return 0;
}