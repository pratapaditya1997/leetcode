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
        vector<vector<int>> a(4, vector<int>(3, 1));
        a[3][0] = a[3][2] = 0;
        
        vector<vector<ll>> old_dp(4, vector<ll>(3, 0)),
                           cur_dp(4, vector<ll>(3, 0));
        
        for (int i=0; i<4; ++i) {
            for (int j=0; j<3; ++j) {
                old_dp[i][j] = a[i][j];
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
                            add(ret, old_dp[ni][nj]);
                        }
                    }
                    cur_dp[i][j] = ret;
                }
            }
            old_dp = cur_dp;
            for (auto& dp: cur_dp) {
                fill(dp.begin(), dp.end(), 0);
            }
        }
        
        ll ans = 0;
        for (int i=0; i<4; ++i) {
            for (int j=0; j<3; ++j) {
                add(ans, old_dp[i][j]);
            }
        }
        
        return (ans % MOD);
    }
};
