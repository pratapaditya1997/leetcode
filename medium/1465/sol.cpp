using ll = long long int;
const int mod = 1e9+7;

class Solution {
public:
    int mul(ll a, ll b) {
        ll res = ((a%mod) * (b%mod)) % mod;
        return res;
    }
    
    int maxArea(int h, int w, vector<int>& a, vector<int>& b) {
        a.push_back(h);
        b.push_back(w);
        int n = a.size(), m = b.size();
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int maxi_width = b[0], maxi_height = a[0];
        for(int i=1; i<n; i++) {
            maxi_height = max(maxi_height, a[i] - a[i-1]);
        }
        for(int i=1; i<m; i++) {
            maxi_width = max(maxi_width, b[i] - b[i-1]);
        }
        return mul(maxi_height, maxi_width);
    }
};
