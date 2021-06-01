const int INF = 1e5;

class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int l, int r) {
        if (l >= r) return 0;
        if (l + 1 == r) return l;
        if (dp[l][r] != -1) return dp[l][r];
        
        int ret = INF;
        // get best element to go for in the current range [l, r]
        for (int i=l; i<=r; ++i) {
            // try going both ways and take the worst case as the answer
            int val = max(f(l, i-1), f(i+1, r)) + i;
            ret = min(ret, val);
        }
        return (dp[l][r] = ret);
    }
    
    int getMoneyAmount(int n) {
        dp = vector<vector<int>> (n+1, vector<int>(n+1, -1));
        return f(1, n);
    }
};
