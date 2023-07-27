class Solution {
public:
    bool check(long long mid , vector<int> &a,long long summ,int n)
    {
        for(int i=a.size()-1;i>=0 && n>0;i--)
        {
            
            if(a[i]>=mid)   summ-=a[i];
            else{
                if(summ/n >= mid)   return true;
                else return false;
            }
            n--;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& a) {
        long long m = a.size();
        sort(a.begin(),a.end());
        long long summ=0;
        for(auto itr:a) summ+=itr;
        long long l = 0;
        long long r = summ;
        while(l<r)
        {
            long long mid =  (l+r)/2 + 1 ;
            // cout<<l<<" "<<mid<<" "<<r<<endl;
            if(check(mid,a,summ,n))
            {
                l=mid;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
};