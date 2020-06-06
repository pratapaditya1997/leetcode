class Solution {
public:
    int cherryPickup(vector<vector<int>>& a) {
        const int n = size(a);
        const int m = size(a[0]);
        
        int dp[m][m][n];
        memset(dp, -1, sizeof dp);
        dp[0][m-1][0] = a[0][0] + a[0][m-1];
        
        for(int row = 1; row < n; row++) {
            for(int c1 = 0; c1 < m; c1++) {
                for(int c2 = 0; c2 < m; c2++) {
                    for(int dx: {1,0,-1}) {
                        for(int dy: {1,0,-1}) {
                            int p_c1 = c1 + dx;
                            int p_c2 = c2 + dy;
                            if(p_c1 < 0 || p_c2 < 0 || p_c1 >= m || p_c2 >= m || dp[p_c1][p_c2][row-1] == -1) continue;
                            int val = dp[p_c1][p_c2][row-1] + a[row][c1] + (c1 == c2 ? 0 : a[row][c2]);
                            dp[c1][c2][row] = max(dp[c1][c2][row], val);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, dp[i][j][n-1]);
            }
        }
        return ans;
    }
};