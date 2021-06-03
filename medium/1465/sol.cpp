typedef long long int ll;

const int MOD = 1e9 + 7;

inline int Mul(ll x, ll y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(0); hc.push_back(h);
        vc.push_back(0); vc.push_back(w);
        
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int max_h = 0, max_v = 0;
        int h_len = hc.size(), v_len = vc.size();
        
        for (int i=0; i<h_len-1; ++i) {
            max_h = max(max_h, hc[i+1] - hc[i]);
        }
        for (int i=0; i<v_len-1; ++i) {
            max_v = max(max_v, vc[i+1] - vc[i]);
        }
        
        return Mul(max_h, max_v);
    }
};
