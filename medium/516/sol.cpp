class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int f(int l, int r, const string& s) {
        if (l == r) return 1;
        if (l + 1 == r) {
            if (s[l] == s[r]) return 2;
            return 1;
        }
        if (dp[l][r] != -1) return dp[l][r];
        
        int ret = 1;
        if (s[l] == s[r]) ret = max(ret, 2 + f(l+1, r-1, s));
        ret = max(ret, f(l+1, r, s));
        ret = max(ret, f(l, r-1, s));
        return dp[l][r] = ret;
    }
    
    int longestPalindromeSubseq(string s) {
        n = s.length();
        dp = vector<vector<int>> (n, vector<int>(n, -1));
        return f(0, n-1, s);
    }
};
