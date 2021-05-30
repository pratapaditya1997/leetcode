typedef long long int ll;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

const ll MOD = 1e9 + 7;

inline void Add(ll& x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

class Solution {
public:
    int m, n;
    
    ll f(int i, int j, int moves_left, vector<vector<vector<ll>>>& dp) {
        if (i == m || j == n || i < 0 || j < 0) return 1;
        if (moves_left == 0) return 0;
        if (dp[i][j][moves_left] != -1) return dp[i][j][moves_left];
        ll ret = 0;
        for (int d=0; d<4; ++d) {
            int ni = i + dx[d], nj = j + dy[d];
            Add(ret, f(ni, nj, moves_left - 1, dp));
        }
        return dp[i][j][moves_left] = ret;
    }
    
    int findPaths(int _m, int _n, int maxMove, int r, int c) {
        m = _m; n = _n;
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(maxMove + 1, -1)));
        return f(r, c, maxMove, dp);
    }
};
