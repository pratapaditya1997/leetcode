class Solution {
public:
    
    int countSubstrings(string s) {
        int n = size(s), ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
            if(i && s[i-1] == s[i]) dp[i-1][i] = 1; 
        }
        for(int len = 3; len <= n; len++) {
            for(int i = n-len; i >= 0; i--) {
                int j = i+len-1;
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
            }
        }
        
        for(auto v: dp) for(int i: v) ans += i;
        return ans;
    }
};
