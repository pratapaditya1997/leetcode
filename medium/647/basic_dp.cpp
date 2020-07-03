class Solution {
public:
    int dp[1001][1001];
    int n;
    string s;
    
    int f(int i, int j) {
        if(i > j) return 0;
        if(j == i+1 || j == i) return s[i] == s[j];
        
        int& ret = dp[i][j];
        if(ret != -1) return ret;
        ret = 0;
        if(s[i] == s[j]) ret = f(i+1, j-1);
        return ret;
    }
    
    int countSubstrings(string str) {
        n = size(str);
        memset(dp, -1, sizeof dp);
        s = str;
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) ans += f(i,j);
        }
        return ans;
    }
};
