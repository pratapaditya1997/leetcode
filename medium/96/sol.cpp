class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int l, int r) {
        if (l >= r) return 1;
        if (l + 1 == r) return 2;
        if (dp[l][r] != -1) return dp[l][r];
        
        int ret = 0;
        for (int i=l; i<=r; ++i) {
            ret += f(l, i-1) * f(i+1, r);
        }
        return (dp[l][r] = ret);
    }
    
    int numTrees(int n) {
        dp = vector<vector<int>> (n+1, vector<int>(n+1, -1));
        return f(1, n);
    }
};
