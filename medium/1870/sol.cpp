class Solution {
public:
    int minSpeedOnTime(vector<int>& d, double hour) {
        int n = d.size();
        if (hour < n-1) return -1;
        
        auto valid = [&](int s) {
            double time_taken = 0.0;
            for (int i=0; i<n; i++) {
                double cur_time = (1.0 * d[i] / s);
                if (i != n-1) time_taken += ceil(cur_time);
                else time_taken += cur_time;
            }
            return (time_taken <= hour);
        };
        
        int l = 1, r = 1e9;
        int ans = r;
        while (l <= r) {
            int m = (l + r) / 2;
            if (valid(m)) {
                ans = m;
                r = m - 1;
            } else l = m + 1;
        }
        
        return ans;
    }
};
