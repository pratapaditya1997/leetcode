class Solution {
public:
    string s;
    vector<vector<int>> dp;
    
    int f(int l, int r) {
        if (l == r) return 1;
        if (l + 1 == r && s[l] == s[r]) return 1;
        if (dp[l][r] != -1) return dp[l][r];
        
        int res = 0;
        if (s[l] == s[r]) res = f(l+1, r-1);
        return dp[l][r] = res;
    }
    
    int countSubstrings(string str) {
        int ans = 0, n = str.length();
        s = str;
        
        dp = vector<vector<int>> (n, vector<int>(n, -1));
        
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                if (f(i, j)) ++ans;
            }
        }
        return ans;
    }
};
