class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int n, int m, const string& s, const string& t) {
        if (n == 0 || m == 0) {
            if (m == 0) return 1;
            return 0;
        }
        
        int& ret = dp[n][m];
        if (ret != -1) return ret;
        
        ret = 0;
        if (s[n-1] == t[m-1]) {
            ret = f(n-1, m-1, s, t) + f(n-1, m, s, t);
        } else {
            ret = f(n-1, m, s, t);
        }
        return ret;
    }
    
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        dp = vector<vector<int>> (n+1, vector<int>(m+1, -1));
        return f(n, m, s, t);
    }
};
