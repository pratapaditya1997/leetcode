const int INF = 1e7;

class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int l, int r, vector<int>& a) {
        if (r-l < 2) return 0;
        if (r-l == 2) {
            return a[l] * a[l+1] * a[r];
        }
        if (dp[l][r] != -1) return dp[l][r];
        
        int ret = INF;
        for (int i=l+1; i<=r-1; ++i) {
            ret = min(ret, a[l] * a[i] * a[r] + f(l, i, a) + f(i, r, a));
        }
        return (dp[l][r] = ret);
    }
    
    int minScoreTriangulation(vector<int>& a) {
        int n = a.size();
        dp = vector<vector<int>> (n, vector<int>(n, -1));
        return f(0, n-1, a);
    }
};
