class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> temp=nums;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             temp[i]=nums[i]
//         }
        sort(temp.begin(),temp.end());
        int val = temp[temp.size()-k];
        cout<<"value of kth largest "<<val<<endl;
  
        
        
        return val;
        
    }
};