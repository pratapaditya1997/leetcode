class Solution {
public:
    int minFlips(string str) {
        int n = str.length();
        vector<int> v(2*n, 0);
        
        for (int i=0; i<2*n; ++i) {
            v[i] = (str[i%n] - '0');
            v[i] ^= (i%2);
        }
        
        int ones = 0, zeros = 0;
        for (int i=0; i<n; ++i) {
            if (v[i]) ++ones;
            else ++zeros;
        }
        
        int ans = min(ones, zeros);
        for (int i=n; i<2*n; ++i) {
            if (v[i-n]) --ones;
            else --zeros;
            
            if (v[i]) ++ones;
            else ++zeros;
            
            ans = min(ans, min(ones, zeros));
        }
        
        return ans;
    }
};
