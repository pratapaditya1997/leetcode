class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int n = a.size();
        
        auto check = [&](int m) {
            int res = 0;
            for (int i=0; i<n; ++i) {
                res += a[i] / m;
                if (a[i] % m != 0) ++res;
            }
            return (res <= h);
        };
        
        int l = 1, r = 1e9, ans = -1;
        while (l <= r) {
            int m = (l + r)/2;
            if (check(m)) {
                ans = m;
                r = m-1;
            } else l = m+1;
        }
        
        return ans;
    }
};
