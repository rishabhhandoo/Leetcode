class Solution {
public:
    static bool compare(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second > b.second);
}
    
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> freq;
        
        vector<pair<int,int>> two;
        
        for(auto itr : arr)
        {
            freq[itr]++;
        }
        
        for(auto itr:freq)
        {
            two.push_back({itr.first,itr.second});
        }
        
        sort(two.begin(),two.end(),compare);
        
        int net=0;
        int count=0;
        for(auto itr: two)
        {
            net+=itr.second;
            count++;
            if(net>=arr.size()/2)
                return count;                
        }
        return count;
        
    }
};