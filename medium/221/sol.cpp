class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> cur(m+1, 0), old(m+1, 0);
        
        int ans = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (a[i-1][j-1] == '0') cur[j] = 0;
                else cur[j] = min(old[j], min(cur[j-1], old[j-1])) + 1;
                ans = max(ans, cur[j]);
            }
            old = cur;
        }
        
        return ans * ans;
    }
};
