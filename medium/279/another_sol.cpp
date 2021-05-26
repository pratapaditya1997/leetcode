const int INF = 1e4 + 4;

class Solution {
public:
    int numSquares(int n) {
        vector<int> ps;
 
        int max_square_idx = (int)sqrt(n) + 1;
        for (int i=1; i <= max_square_idx; ++i) {
            ps.push_back(i*i);
        }
        
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
