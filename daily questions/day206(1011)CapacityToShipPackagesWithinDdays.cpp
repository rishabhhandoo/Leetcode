class Solution {
public:
    int check_days(vector<int>& weights,int cut)
    {
        int counter=1;
        int summ=0;
        for(int i=0;i<weights.size();i++)
        {
            summ+=weights[i];

            if(summ>cut)
            {
                counter++;
                summ=weights[i];
            }
        }
        return counter;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n=weights.size();
        int summ=0;
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            summ+=weights[i];
            maxx=max(weights[i],maxx);
        }
        int l=maxx;
        int r=summ;

        while(l<r)
        {
            int mid=l+(r-l)/2;
            int d=check_days(weights,mid);
            if(d<=days)
            {
                r=mid;
            }else if(d>days)
            {
                l=mid+1;
            }

            cout<<l<<" "<<mid<<" "<<r<<endl;
            cout<<d<<" -> days"<<endl<<endl;
        }
        return l;
    }
};