class Solution {
public:
    int maxLength(vector<int>& a, int k) {
        int n = a.size();
        
        auto check = [&](int m) {
            int res = 0;
            for (int len: a) {
                res += len/m;
            }
            return res >= k;
        };
        
        int l = 1, r = 1e9, ans = 0;
        while (l <= r) {
            int m = (l + r)/2;
            if (check(m)) {
                ans = m;
                l = m+1;
            } else r = m-1;
        }
        
        return ans;
    }
};
