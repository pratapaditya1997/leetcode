typedef pair<int, int> pii;
typedef long long int ll;

const int INF = 1e9 + 7;

class Solution {
public:
    int minRefuelStops(int target, int sf, vector<vector<int>>& a) {
        vector<pii> v;
        
        v.push_back({0, sf});
        for (auto& p: a) {
            v.push_back({p[0], p[1]});
        }
        v.push_back({target, INF});
        
        int n = v.size();
        vector<vector<ll>> dp(n, vector<ll>(n, -1));
        dp[0][0] = sf;
        
        for (int i=1; i<n; ++i) {
            for (int j=0; j<=i; ++j) {
                ll ret = -1, delta = v[i].first - v[i-1].first;
                
                // fill at current station
                if (j-1 >= 0 && dp[i-1][j-1] != -1 && (dp[i-1][j-1] - delta >= 0)) {
                    ret = max(ret, dp[i-1][j-1] - delta + v[i].second);
                }
                
                // do not fill at current station
                if (dp[i-1][j] != -1 && dp[i-1][j] - delta >= 0) {
                    ret = max(ret, dp[i-1][j] - delta);
                }
                dp[i][j] = ret;
            }
        }
        
        for (int j = 0; j<n; ++j) {
            if (dp[n-1][j] != -1) return j;
        }
        
        return -1;
    }
};
