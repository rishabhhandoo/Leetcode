class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> players;
        int n = scores.size();
        int summ = 0;

        for(int i=0;i<n;i++)
        {
            players.push_back({scores[i],ages[i]});
            summ+=scores[i];
        }

        sort(players.begin(),players.end());
        int ans =0;
        for(int i=0;i<n;i++)
        {
            int ia = players[i].second;
            int curr=players[i].first;
            for(int j=0;j<i;j++)
            {
                int ja = players[j].second;
                if(ja<=ia)
                {
                    curr = max(curr,players[i].first + players[j].first);
                }
            }
            players[i].first = curr;
            ans = max(curr,ans);
        }
        return ans;
    }
};