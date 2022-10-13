// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    // int dp[]
	int helper(int arr[],int ind,vector<int> &dp)
	{
	    if(ind==0)  return arr[0];
	    if(ind<0) return 0;
	    if(dp[ind]!=-1 )return dp[ind];
	    int take = arr[ind] + helper(arr,ind-2,dp);
	    int not_take = 0+ helper(arr,ind-1,dp);
	    
	    return dp[ind] = max(take,not_take);
	}
	
	
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,-1);
	    int ans = helper(arr,n-1,dp);
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends