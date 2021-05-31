class Solution {
public:
    int n;
    vector<vector<int>> dp, maxi;
    
    int f(int l, int r, vector<int>& a) {
        if (l == r) return 0;
        if (l + 1 == r) return a[l] * a[r];
        if (dp[l][r] != 0) return dp[l][r];
        
        int val = INT_MAX;
        for (int i=l; i<r; ++i) {
            val = min(val, f(l, i, a) + f(i + 1, r, a) + maxi[l][i] * maxi[i + 1][r]);
        }
        return dp[l][r] = val;
    }
    
    int mctFromLeafValues(vector<int>& a) {
        n = a.size();
        
        dp = vector<vector<int>> (n, vector<int>(n, 0));
        maxi = vector<vector<int>> (n, vector<int>(n, 0));
        
        for (int i=0; i<n; ++i) {
            int val = a[i];
            for (int j=i; j<n; ++j) {
                val = max(val, a[j]);
                maxi[i][j] = val;
            }
        }
            
        return f(0, n-1, a);
    }
};
