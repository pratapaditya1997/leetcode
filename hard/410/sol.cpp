class Solution {
public:
    bool check(vector<int>& a, int m, int x, int n) {
        int sum = 0, sets = 1;
        for (int i=0; i<n; ++i) {
            sum += a[i];
            if (sum > x) {
                sum = a[i];
                if (sum > x) return false;
                ++sets;
            }
        }
        return (sets <= m);
    }
    
    int splitArray(vector<int>& a, int m) {
        int n = a.size();
        
        int l = 0, r = 1e9, ans = -1;
        while (l <= r) {
            int x = (l + r) / 2;
            if (check(a, m, x, n)) {
                ans = x;
                r = x - 1;
            } else l = x + 1;
        }
        return ans;
    }
};
