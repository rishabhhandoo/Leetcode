// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string,int> umap;
//         vector<string> ans;
//         for(auto itr:words)
//         {
//             umap[itr]++;
//         }
        
//         // priority_queue<pair<int,string> , vector<pair<int,string>> , greater<pair<int,string>>> pq;
//         priority_queue<pair<int,string>> pq;
//         for(auto itr : umap)
//         {
//             cout<<itr.first<<" "<<itr.second<<endl;
//             if(pq.size()<k)
//             {
//                 if(pq.size()>1 && itr.first<pq.top().second)
//                 {
//                         auto hmm = pq.top();
//                         pq.pop();
//                         pq.push({itr.second,itr.first});
//                         pq.push(hmm);
//                 }
//                 else    pq.push({itr.second,itr.first});
//             }else{
//                 if(itr.second>pq.top().first)
//                 {
//                     pq.pop();
//                     pq.push({itr.second,itr.first});
//                 }
//                 if(itr.second==pq.top().first)
//                 {
//                     if(itr.first<pq.top().second)
//                     {   
//                         pq.pop();
//                         pq.push({itr.second,itr.first});
//                     }
//                 }
//             }
//         }
//         while(pq.empty()!=true)
//         {
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
//         // reverse(ans.begin(),ans.end());
        
//         return ans;
//     }
// };
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq, topk;
        auto comp= [&](const pair<string, int> & v1,const pair<string,int> &v2) {
            return v1.second>v2.second || (v1.first<v2.first && v1.second==v2.second);
            };
        set<pair<string,int>, decltype(comp)> s(comp);
        for(auto &w:words){
            freq[w]++;
            auto it = s.find({w,freq[w]-1});
            if(it!=s.end())s.erase(it);
            s.emplace(w,freq[w]);
            if(s.size()>k)s.erase(--s.end());
        }
        vector<string>res;
        for(auto&e:s)res.push_back(e.first);
        return res; 
    }
};
