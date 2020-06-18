const int mod = 1e9+7;

class Solution {
public:
    vector<int> h;
    int dp[1<<10][41] = {};
    int allmask, n;
    
    void add(int& a, int b) {
        a += b;
        if(a >= mod) a -= mod;
    }
    
    int f(int mask, int idx) {
        if(mask == allmask) return 1;
        if(idx == 41) return 0;
        if(dp[mask][idx] != -1) return dp[mask][idx];
        int ret = 0;
        for(int i=0; i<n; i++) {
            if(mask&(1<<i)) continue;
            if(h[idx]&(1<<i)) add(ret, f(mask|(1<<i), idx+1));
        }
        add(ret, f(mask, idx+1));
        return dp[mask][idx] = ret;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        n = size(hats);
        allmask = (1<<n)-1;
        memset(dp, -1, sizeof dp);
        h.resize(41,0);
        for(int i=0; i<n; i++) {
            for(int hat: hats[i]) {
                h[hat] |= (1<<i);
            }
        }
        return f(0,1);
    }
};
