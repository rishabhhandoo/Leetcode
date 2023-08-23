class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int> umap;
        priority_queue<pair<int,char>> pq;
        for(auto itr:s) umap[itr]++;
        for(auto itr:umap){
            pq.push({itr.second,itr.first});
        }
        if(pq.top().first > (n+1)/2)    return "";
        string ans="";
        while(!pq.empty())
        {
            ans+=pq.top().second;
            auto temp = pq.top();
            temp.first--;
            pq.pop();
            if(!pq.empty()) 
            {
                ans+=pq.top().second;
                auto temp1 = pq.top();
                pq.pop();
                temp1.first--;
                if(temp1.first>0)
                    pq.push(temp1);
            }
            if(temp.first>0)
                pq.push(temp);
        }
        return ans;
    }
};