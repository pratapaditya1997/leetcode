class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> x;
        
        for (auto& p: points) {
            x[p[0]].insert(p[1]);
        }
        
        int ans = INT_MAX;
        for (auto i = begin(x); i != end(x); ++i) {
            for (auto j = next(i); j != end(x); ++j) {
                if (size(i->second) < 2 || size(j->second) < 2) continue;
                vector<int> y;
                set_intersection(begin(i->second), end(i->second),
                                 begin(j->second), end(j->second),
                                 back_inserter(y));
                for (int k = 1; k < y.size(); ++k) {
                    ans = min(ans, abs(i->first - j->first) * (y[k] - y[k-1]));
                }
            }
        }
        
        if (ans == INT_MAX) return 0;
        return ans;
    }
};
