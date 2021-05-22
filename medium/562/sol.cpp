class Solution {
public:
    int longestLine(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();        
        vector<vector<int>> cur(m+1, vector<int>(4, 0)),
                            old(m+1, vector<int>(4, 0));
        
        int ans = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (a[i-1][j-1]) {
                    cur[j][0] = cur[j-1][0] + 1;
                    cur[j][1] = old[j][1] + 1;
                    cur[j][2] = old[j-1][2] + 1;
                    if (j < m) cur[j][3] = old[j+1][3] + 1;
                } else fill(cur[j].begin(), cur[j].end(), 0);
                ans = max({ans, cur[j][0], cur[j][1], cur[j][2], cur[j][3]});
            }
            old = cur;
        }
        
        return ans;
    }
};
