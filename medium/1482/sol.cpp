class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int l = 0, r = 1e9, ans = -1;
        int n = size(a);
        
        auto check = [&a, &n, &k, &m] (int x) {
            int tot = 0, cur = 0;
            for(int i=0; i<n; i++) {
                if(a[i] <= x) cur++;
                else cur = 0;
                if(cur == k) {
                    tot++;
                    cur = 0;
                }
            }
            if(cur == k) tot++;
            return (tot >= m);
        };
        
        while(l <= r) {
            int mid = (l+r)/2;
            if(check(mid)) {
                ans = mid;
                r = mid-1;
            } else l = mid+1;
        }
        
        return ans;
    }
};
