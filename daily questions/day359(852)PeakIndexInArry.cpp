class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
    
        int l=0;
        int r=a.size()-1;
        
        while(l<=r)
        {
            int mid= l + (r-l)/2;
            cout<<"value of mid"<<mid<<endl;
            
            if(a[mid]>a[mid+1] && a[mid] > a[mid-1]){
                return mid;
            }else if(a[mid]>a[mid+1]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
    }
};