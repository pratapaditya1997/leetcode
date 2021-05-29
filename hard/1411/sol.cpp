typedef long long int ll;

const ll MOD = 1e9 + 7;

inline ll Add(ll x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline ll Mul(ll x, ll y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

class Solution {
public:
    int numOfWays(int n) {
        vector<ll> y(n), w(n);
        
        y[0] = w[0] = 6;
        for (int i=1; i<n; ++i) {
            y[i] = Add(Mul(3, y[i-1]), Mul(2, w[i-1]));
            w[i] = Add(Mul(2, y[i-1]), Mul(2, w[i-1]));
        }
        
        return Add(y[n-1], w[n-1]);
    }
};
