class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1=-1;
        int c1=0;
        int m2=-1;
        int c2=0;


        for(auto itr : nums)
        {
            if(m1==itr) c1++;
            else if(m2==itr) c2++;
            else if(c1==0)
            {
                m1=itr;
                c1=1;
            }else if(c2==0)
            {
                m2=itr;
                c2=1;
            }else{
                c1--,c2--;
            }
        }

        //now iterating to see if they are right
        c1=0,c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==m1)
            {
                c1++;
            }
            if(nums[i]==m2)
            {
                c2++;
            }
        }
        cout<<nums.size()/3;
        vector<int> ans;
        if(c1>nums.size()/3 )
        {
            ans.push_back(m1);
        }
        if(c2>nums.size()/3 && m1!=m2)
        {
            ans.push_back(m2);
        }
        
        return ans;
        
    }
};