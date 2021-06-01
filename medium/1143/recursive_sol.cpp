class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int n, int m, const string& s, const string& t) {
        if (n < 0 || m < 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        
        int ret;
        if (s[n] == t[m]) ret = 1 + f(n-1, m-1, s, t);
        else ret = max(f(n-1, m, s, t), f(n, m-1, s, t));
        return dp[n][m] = ret;
    }
    
    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        dp = vector<vector<int>> (n, vector<int>(m, -1));
        return f(n-1, m-1, s, t);
    }
};
