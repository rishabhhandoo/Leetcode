class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> nge(nums.size());
        stack<int> s;

        for (int i = 0; i < 2 * nums.size(); i++)
        {
            int n = i % (nums.size());
            if (i < nums.size())
            {
                while ((!s.empty()) && nums[s.top()] < nums[n])
                {
                    nge[s.top()] = nums[n];
                    s.pop();
                }
                s.push(n);
            }
            else
            {
                while ((!s.empty()) && nums[s.top()] < nums[n])
                {
                    nge[s.top()] = nums[n];
                    s.pop();
                }
            }
        }
        while (!s.empty())
        {
            nge[s.top()] = -1;
            s.pop();
        }
        return nge;
    }
};