typedef long long int ll;

const ll mod = 1e9 + 7;

inline ll add(ll x, ll y) {x +=y; if (x >= mod) x -= mod; return x;}
inline ll mul(ll x, ll y) {return ((x % mod) * (y % mod)) % mod;}

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        
        unordered_map<int, int> m;
        for (int i=0; i<n; i++) m[a[i]] = i;
        
        vector<ll> dp(n, 1);
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (a[i] % a[j] != 0) continue;
                if (m.find(a[i] / a[j]) == m.end()) continue;
                int x = m[a[j]], y = m[a[i] / a[j]];
                dp[i] = add(dp[i], mul(dp[x], dp[y]));
            }
        }
        
        ll ans = 0;
        for (ll x: dp) ans = add(ans, x);
        return ans % mod;
    }
};
