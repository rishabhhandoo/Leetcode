class Solution {
public:
    double average(vector<int>& salary) {
        int maxx=INT_MIN;
        int minn=INT_MAX;
        double summ=0;
        for(auto itr:salary)
        {
            summ+=itr;
            minn=min(minn,itr);
            maxx=max(maxx,itr);
        }
        summ = summ - maxx-minn;

        double n = salary.size()-2;
        return (double)summ/(double)n;
    }
};