typedef long long int ll;

const ll MOD = 1e9 + 7;

inline void Add(ll& x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

const vector<vector<int>> a{{0,1,0,0,0},
                            {1,0,1,0,0},
                            {1,1,0,1,1},
                            {0,0,1,0,1},
                            {1,0,0,0,0}};

class Solution {
public:
    int countVowelPermutation(int n) {
        if (n == 1) return 5;
        
        vector<ll> old_dp(5, 1), cur_dp(5, 0);
        ll ans = 0;
        
        for (int i=2; i<=n; ++i) {
            for (int v=0; v<5; ++v) {
                ll val = 0;
                for (int pv=0; pv<5; ++pv) {
                    if (a[pv][v]) Add(val, old_dp[pv]);
                }
                cur_dp[v] = val;
                if (i == n) Add(ans, val);
            }
            old_dp = cur_dp;
            fill(cur_dp.begin(), cur_dp.end(), 0);
        }
        
        return ans;
    }
};
