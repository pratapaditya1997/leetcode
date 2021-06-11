vector<int> a;
vector<vector<int>> dp, sum;
 
int f(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
 
    int ret = (sum[l][r] - a[l]) - f(l+1, r);
    ret = max(ret, (sum[l][r] - a[r]) - f(l, r-1));
    return (dp[l][r] = ret);
}

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        
        a = stones;
        dp = vector<vector<int>> (n, vector<int>(n, -1));
        sum = vector<vector<int>> (n, vector<int>(n, 0));

        for (int i=0; i<n; ++i) {
            int cur = 0;
            for (int j=i; j<n; ++j) {
                cur += a[j];
                sum[i][j] = cur;
            }
        }

        return f(0, n-1);
    }
};
