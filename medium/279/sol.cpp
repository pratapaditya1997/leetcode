const int N = 1e4 + 4;
const int INF = 1e4 + 4;

vector<int> ps;

void init() {
    for (int i=1; i<N; ++i) {
        int sr = (int)sqrt(i);
        if (sr * sr == i) {
            ps.push_back(i);
        }
    }
}

class Solution {
public:
    int numSquares(int n) {
        if (ps.empty()) init();
        
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        
        for (int i=1; i<=n; ++i) {
            for (int s: ps) {
                if (i-s < 0) break;
                dp[i] = min(dp[i], dp[i-s] + 1);
            }
        }
        
        return dp[n];
    }
};
