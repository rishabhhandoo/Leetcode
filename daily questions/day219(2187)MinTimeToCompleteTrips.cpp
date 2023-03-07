class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long l = 0;
        long long r = (long)time[0]*(long)totalTrips;
        cout<<"value of r"<<r<<endl;
        long long n = time.size();

        while(l<r)
        {
            long long mid = l + (r-l)/2;
            long long trips=0;
            for(long long i=0;i<n;i++)
            {
                trips+=mid/time[i];
            }
            if(trips>=totalTrips)   r=mid;
            else    l=mid+1;
        }
        return l;        
    }
};