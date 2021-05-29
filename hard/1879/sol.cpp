int n;
int all_mask;

vector<vector<int>> dp;

int f(int idx, int mask, vector<int>& a, vector<int>& b) {
    if (idx == n) {
        return 0;
    }
    if (dp[idx][mask] != -1) return dp[idx][mask];
    int ret = INT_MAX;
    for (int i=0; i<n; ++i) {
        if (mask&(1<<i)) continue;
        ret = min(ret, f(idx+1, (mask|(1<<i)), a, b) + (a[idx] ^ b[i]));
    }
    return (dp[idx][mask] = ret);
}

class Solution {
public:
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        n = a.size();
        all_mask = (1<<n);
        dp = vector<vector<int>> (n, vector<int>(all_mask, -1));
        return f(0, 0, a, b);
    }
};
