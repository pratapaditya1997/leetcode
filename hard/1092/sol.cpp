class Solution {
public:
    
    string LCS(const string& s, const string& t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int x = n, y = m;
        string ans = "";
        while (x > 0 && y > 0) {
            if (s[x - 1] == t[y - 1]) {
                ans += s[x - 1];
                --x; --y;
            } else {
                if (dp[x - 1][y] >= dp[x][y - 1]) --x;
                else --y;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string shortestCommonSupersequence(string s, string t) {
        string lcs = LCS(s, t);
        
        int i=0, j=0;
        string ans = "";
        for (char c: lcs) {
            while (s[i] != c) {
                ans += s[i];
                ++i;
            }
            while (t[j] != c) {
                ans += t[j];
                ++j;
            }
            ans += c;
            ++i;
            ++j;
        }
        
        ans += s.substr(i);
        ans += t.substr(j);
        return ans;
    }
};
