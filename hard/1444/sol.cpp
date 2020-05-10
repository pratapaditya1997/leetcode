using ll = long long int;

class Solution {
public:
    const ll mod = 1e9+7;

    int n,m;
    ll dp[55][55][15];
    ll pre[55][55];
    
    void add(ll& a, ll b) {
        a += b;
        if(a >= mod) a -= mod;
    }

    int f(int r, int c, int left) {
        if(dp[r][c][left] != -1) return dp[r][c][left];
        if(left == 0) {
            dp[r][c][0] = (pre[r][c]) ? 1 : 0;
            return dp[r][c][0];
        }
        ll res = 0;
        for(int i=r+1; i<n; i++) {
            if((pre[r][c] - pre[i][c]) && pre[i][c] >= left) {
                add(res, f(i,c,left-1));
            }
        }
        for(int j=c+1; j<m; j++) {
            if((pre[r][c] - pre[r][j]) && pre[r][j] >= left) {
                add(res, f(r,j,left-1));
            }
        }

        dp[r][c][left] = res;
        return res;
    }

    int ways(vector<string>& pizza, int cuts) {
        n = pizza.size();
        m = pizza[0].length();

        memset(pre, 0, sizeof(pre));
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                pre[i][j] = pre[i][j+1] + pre[i+1][j] - pre[i+1][j+1];
                pre[i][j] += (pizza[i][j] == 'A') ? 1 : 0;
            }
        }
        
        memset(dp,-1,sizeof(dp));
        return f(0,0,cuts-1);
    }
};