#define ff first
#define ss second
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& a) {
        map<string, set<pair<string, int>>> mp;
        int sz = a.size();
        vector<int> vis(sz + 1, 0);

        for(int i = 0; i < sz; i++) 
            mp[a[i][0]].insert({a[i][1], i});

        vector<string> ans, v = {"JFK"};

        function<int(string)> dfs = [&](string s) {
            if(int(v.size()) == sz + 1) { ans = v; return 1; }
            for(auto &x: mp[s]) {
                if(!vis[x.ss]) {
                    v.push_back(x.ff); vis[x.ss] = 1;
                    if(dfs(x.ff)) return 1;
                    v.pop_back(); vis[x.ss] = 0;
                }
            }
            return 0;
        };
        dfs("JFK");

        return ans;
    }   
};