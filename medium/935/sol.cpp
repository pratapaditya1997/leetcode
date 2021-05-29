typedef long long int ll;

const ll MOD = 1e9 + 7;

int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

inline void add(ll& x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

class Solution {
public:
    bool Valid(int x, int y) {
        return (x >= 0 && y >= 0 && x < 4 && y < 3);
    }
    
    int knightDialer(int n) {
        ll dp[4][3][n + 1];
        memset(dp, 0, sizeof dp);
        
        vector<vector<int>> a(4, vector<int>(3, 1));
        a[3][0] = a[3][2] = 0;
        
        for (int i=0; i<4; ++i) {
            for (int j=0; j<3; ++j) {
                dp[i][j][1] = a[i][j];
            }
        }
        
        for (int k=2; k<=n; ++k) {
            for (int i=0; i<4; ++i) {
                for (int j=0; j<3; ++j) {
                    if (!a[i][j]) continue;
                    ll ret = 0;
                    for (int d=0; d<8; ++d) {
                        int ni = i + dx[d], nj = j + dy[d];
                        if (Valid(ni, nj) && a[ni][nj]) {
                            add(ret, dp[ni][nj][k-1]);
                        }
                    }
                    dp[i][j][k] = ret;
                }
            }
        }
        
        ll ans = 0;
        for (int i=0; i<4; ++i) {
            for (int j=0; j<3; ++j) {
                add(ans, dp[i][j][n]);
            }
        }
        
        return (ans % MOD);
    }
};
