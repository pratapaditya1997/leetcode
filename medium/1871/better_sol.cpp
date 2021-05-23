class Solution {
public:
    bool canReach(string s, int min_jump, int max_jump) {
        int n = s.length();
        if (s[n-1] != '0') return false;
        
        vector<bool> dp(n, false);
        dp[0] = true;
        int pre = 0; 
        
        for (int i=1; i<n; i++) {
            if (i - min_jump >= 0) pre += dp[i - min_jump];
            if (i - max_jump -1 >= 0) pre -= dp[i - max_jump - 1];
            dp[i] = (pre > 0 && s[i] == '0');
        }
        
        return dp[n-1];
    }
};
