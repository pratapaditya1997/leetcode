class Solution {
public:
    int dp[501][501] = {};
    
    int f(vector<int>& a, int i, int t) {
        if(i == a.size()) return 0;
        if(dp[i][t]) return dp[i][t];
        dp[i][t] = max(f(a,i+1,t), f(a,i+1,t+1) + a[i]*t);
        return dp[i][t];
    }
    
    int maxSatisfaction(vector<int>& a) {
        int n = size(a);
        sort(begin(a), end(a));
        return f(a,0,1);
    }
};
