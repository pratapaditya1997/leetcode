class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int> l(n), r(n);
        
        l[0] = 1;
        for (int i=1; i<n; ++i) {
            if (a[i] > a[i-1]) l[i] = l[i-1] + 1;
            else l[i] = 1;
        }
        
        r[n-1] = 1;
        for (int i=n-2; i>=0; --i) {
            if (a[i] > a[i+1]) r[i] = r[i+1] + 1;
            else r[i] = 1;
        }
        
        int res = 0;
        for (int i=0; i<n; ++i) res += max(l[i], r[i]);
        return res;
    }
};
