#include<bits/stdc++.h>
using namespace std;
struct info
{
    int open , close,full;
    info(int _open,int _close,int _full)
    {
        open = _open;
        close =_close;
        full = _full;
    }
}
void build(int ind,int low,int high,info seg[],string s)
{
    if(low==high)   
    {
        if(s[low]=='(')
        {
            seg[ind].open=1;
        }else{
            seg[ind].close=1;
        }
        return;
    }
    int mid = (low+right)/2;
    build(2*ind +1,low,mid,seg,s);
    build(2*ind +2,mid+1,high,seg,s);
    auto left = seg[2*ind+1];
    auto right = seg[2*ind+2];
    info[ind].full = left.full + right.full + min(left.open,right.close);
    info[ind].open = left.open+right.open - min(left.open,right.close);
    info[ind].close = left.close+right.close - min(left.open,right.close);
}
info query(int ind,int low,int high,int l,int r,info seg[])
{
    //no overlap
    if(high<l || r <low)
    {
        return info();
    }
    //full overlap
    if(l<=low && r>=high)
    {
        return seg[ind];
    }
    int mid = (l+r)/2;
    int left = query(ind*2 +1,low,mid,l,r,seg);
    int right = query(ind*2 +2,mid+1,high,l,r,seg);
    info temp = new info();
    temp.full = left.full + right.full + min(left.open,right.close);
    temp.open = left.open+right.open - min(left.open,right.close);
    temp.close = left.close+right.close - min(left.open,right.close);
    
    return temp;
}
int main()
{
    string s;
    cin>>s;
    int n = s.size();
    info seg[4*n];
    build(0,0,n-1,seg,s);
    int q;
    cin>>q;

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        query(0,0,n-1,l,r);
    }
return 0;
}