int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        double dp[n][n][k+1];
        memset(dp, 0.0, sizeof dp);
        dp[r][c][0] = 1.0;
        
        for (int t=1; t<=k; ++t) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    double val = 0.0;
                    for (int d=0; d<8; ++d) {
                        int ni = i + dx[d], nj = j + dy[d];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                        val += dp[ni][nj][t-1];
                    }
                    dp[i][j][t] = (val / 8.0);
                }
            }
        }
        
        double ans = 0.0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                ans += dp[i][j][k];
            }
        }
        
        return ans;
    }
};
