class Solution {
public:
    int dp[1005][1005];
    string str;
    
    int f(int i, int j) {
        if(i>j) return 0;
        if(i == j) dp[i][j] = 1;
        else if(j == i+1) dp[i][j] = (str[i] == str[j]);
        else dp[i][j] = (str[i] == str[j]) && f(i+1,j-1);
        return dp[i][j];
    }
    
    string longestPalindrome(string s) {
        str = s;
        int n = s.length(), ans = 0;
        if(n == 0) return "";
        
        memset(dp,-1,sizeof dp);
        int l;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dp[i][j] == -1) f(i,j);
                if(dp[i][j] && j-i+1 > ans) {
                    ans = j-i+1;
                    l = i;
                }
            }
        }
        return s.substr(l,ans);
    }
};
