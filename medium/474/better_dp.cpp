typedef pair<int, int> pii;

class Solution {
public:
    pii GetCounts(const string& str) {
        int z = 0, o = 0;
        for (char c: str) {
            if (c == '0') ++z;
            else ++o;
        }
        return {z, o};
    }
    
    int findMaxForm(vector<string>& strs, int W0, int W1) {
        int n = strs.size();
        vector<int> zero_w(n + 1, 0), one_w(n + 1, 0);
        
        for (int i=1; i<=n; ++i) {
            pii cnt = GetCounts(strs[i-1]);
            zero_w[i] = cnt.first;
            one_w[i] = cnt.second;
        }
        
        int dp[W0 + 1][W1 + 1];
        memset(dp, 0, sizeof dp);
        
        for (int i = 1; i <= n; ++i) {
            for (int j = W0; j >= zero_w[i]; --j) {
                for (int k = W1; k >= one_w[i]; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - zero_w[i]][k - one_w[i]] + 1);
                }
            }
        }
        
        return dp[W0][W1];
    }
};
