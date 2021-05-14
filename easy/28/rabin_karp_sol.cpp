typedef long long int ll;

const int p = 31;
const int m = 1e9 + 9;

class Solution {
public:
    int strStr(string t, string s) {
        int S = s.size(), T = t.size();
        if (S == 0) return 0;

        vector<ll> p_pow(max(S,T));
        p_pow[0] = 1;
        for (int i=1; i<(int)p_pow.size(); i++) {
            p_pow[i] = (p_pow[i-1] * p) % m; 
        }

        vector<ll> h(T + 1, 0);
        for (int i=0; i<T; i++) {
            h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
        }

        ll h_s = 0;
        for (int i=0; i<S; i++) {
            h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
        }

        for (int i=0; i+S-1 < T; i++) {
            ll cur_h = (h[i+S] - h[i] + m) % m;
            if (cur_h == h_s * p_pow[i] % m) {
                return i;
            }
        }

        return -1;
    }
};
