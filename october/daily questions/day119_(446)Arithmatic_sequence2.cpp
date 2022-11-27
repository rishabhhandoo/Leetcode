class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A, int res = 0) {
    unordered_map<int, int> m[max(1, (int)A.size())];
    unordered_set<int> s(begin(A), end(A));
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < i; ++j) {
            long d = (long)A[i] - A[j];
            if (d < INT_MIN || d > INT_MAX)
                continue;
            auto it = m[j].find(d);
            int cnt = it == end(m[j]) ? 0 : it->second;
            if (s.count((long)A[i] + d))
                m[i][d] += cnt + 1;
            res += cnt;
        }
    return res;
}
};