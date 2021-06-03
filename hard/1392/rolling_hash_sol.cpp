typedef long long int ll;

const ll p = 31;
const ll mod = 1e9 + 9;

inline ll mul(ll a, ll b) {
    return ((a%mod) * (b%mod)) % mod;
}

ll power(ll a, ll p) {
    ll res = 1;
    for (; p; p/=2) {
        if (p&1) res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}

inline ll inv(ll a) {
    return power(a, mod-2);
}

class Solution {
public:
    void compute_pows(vector<ll>& p_pow, vector<ll>& ip_pow, int n) {
        p_pow[0] = 1;
        for (int i=1; i<n; ++i) {
            p_pow[i] = (p_pow[i-1] * p) % mod;
            ip_pow[i] = inv(p_pow[i]);
        }
    }
    
    ll get_hash(int l, int r, vector<ll>& ip_pow, vector<ll>& h) {
        ll res = (h[r] - h[l-1] + mod) % mod;
        res = mul(res, ip_pow[l]);
        return res % mod;
    }
    
    string longestPrefix(string s) {
        int n = s.length();
        
        vector<ll> p_pow(n+1), ip_pow(n+1), h(n+1, 0);
        compute_pows(p_pow, ip_pow, n+1);
        
        for (int i=0; i<n; ++i) {
            h[i+1] = (h[i] + (s[i]-'a'+1) * p_pow[i]) % mod;
        }
        
        int idx = -1;
        // using 1 based indexing as it is used everywhere in p_pow and ip_pow
        for (int i=n-1; i>=1; --i) {
            // [0, i] && [n-1-i, n-1]
            if (get_hash(1, i, ip_pow, h) == get_hash(n-i+1, n, ip_pow, h)) {
                idx = i;
                break;
            }
        }
        
        if (idx == -1) return "";
        return s.substr(0, idx);
    }
};
