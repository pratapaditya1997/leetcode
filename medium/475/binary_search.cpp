class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        auto check = [&heaters, &houses] (int x) {
            for (int pos: houses) {
                int l = pos - x, r = pos + x;
                auto it = lower_bound(heaters.begin(), heaters.end(), l);
                if (it == heaters.end()) return false;
                if (*it > r) return false;
            }
            return true;
        };
        
        int lo = 0, hi = 1e9, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        
        return ans;
    }
};
