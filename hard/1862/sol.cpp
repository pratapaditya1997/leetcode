typedef long long int ll;

const ll mod = 1e9 + 7;
const int N = 2e5 + 5;

inline ll add(ll x, ll y) { x += y; if (x >= mod) x -= mod; return x;}
inline ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod;}

class fenwick {
public:
    vector<int> bit;
    int n;
 
    fenwick(int _n): n(_n) {
        bit.resize(n);
    }
 
    void modify(int x, int v) {
        while(x < n) {
            bit[x] += v;
            x |= (x+1);
        }
    }
 
    int get(int x) {
        int v = 0;
        while(x >= 0) {
            v += bit[x];
            x = (x & (x+1)) - 1;
        }
        return v;
    }

    int getRange(int l, int r) {
        return get(r) - get(l-1);
    }
};

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& a) {
        int n = a.size();
        ll ans = 0;
        int maxi = 0;
        
        fenwick f(N);
        
        set<int> s;
        for (int i=0; i<n; i++) {
            f.modify(a[i], 1);
            s.insert(a[i]);
            maxi = max(maxi, a[i]);
        }
        
        for (int x: s) {
            int multiplier = maxi / x;
            int self_cnt = f.getRange(x, x);
            for (int i = 1; i <= multiplier; i++) {
                int l = i * x, r = (i + 1) * x - 1;
                int y = f.getRange(l, r);
                ll contrib = mul(self_cnt, mul(y, i));
                ans = add(ans, contrib); 
            }
        }
        
        return ans;
    }
};
