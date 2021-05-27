const int INF = 1e9;

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    
    int f(int i, int j, vector<vector<int>>& a) {
        if (i >= n || j >= m) return INF;
        if (i == n-1 && j == m-1) {
            return (a[i][j] <= 0) ? -a[i][j] + 1 : 1;
        }
        if (dp[i][j] != INF) return dp[i][j];
        
        int ret = INF;
        ret = min(ret, f(i, j+1, a));
        ret = min(ret, f(i+1, j, a));
        
        ret -= a[i][j];
        dp[i][j] = (ret <= 0) ? 1 : ret;
        return dp[i][j];
    }
    
    int calculateMinimumHP(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        dp = vector<vector<int>> (n, vector<int>(m, INF));
        
        return f(0, 0, a);
    }
};
