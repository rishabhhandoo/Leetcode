class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size();
        int m = a[0].size();

        int l=0;
        int r= n*m-1;

        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int i = mid/m;
            int j = mid%m;
            if(a[i][j] == target)   return true;
            else if(a[i][j]>target)
            {
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        return false;
    }
};


// row -> mid/n
//col -> mid%4