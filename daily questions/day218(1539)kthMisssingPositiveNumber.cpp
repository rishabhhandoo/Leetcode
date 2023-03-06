
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //first we make array b
        int n = arr.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(arr[mid]-mid-1 < k)
            {
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l+k;
        //now find the upper bound of k
        //2 3 4 '7' 11 arr
        //1 1 1  3  6  b and k = 5
    }
};