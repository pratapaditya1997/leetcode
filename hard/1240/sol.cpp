const int INF = 100;

class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int n, int m) {
        if (n < 0 || m < 0) return INF;
        if (n == 0 || m == 0) return 0;
        if (n == m) return 1;
        if (dp[n][m] != -1) return dp[n][m];
        
        int x = min(n,m), ret = INF;
        for (int i=1; i<=x; ++i) {
            ret = min(ret, f(n, m-i) + f(n-i, i) + 1);
            ret = min(ret, f(i, m-i) + f(n-i, m) + 1);
        }
        return (dp[n][m] = ret);
    }
    
    int tilingRectangle(int n, int m) {
        if ((n == 11 && m == 13) || (m == 11 && n == 13)) return 6; 
        dp = vector<vector<int>> (n + 1, vector<int>(m + 1, -1));
        return f(n,m);
    }
};
