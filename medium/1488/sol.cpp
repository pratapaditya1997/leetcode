iclass Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = size(rains);
        vector<int> ans(n, -1);
        
        unordered_map<int, int> last_fill;
        set<int> dry_days;
        for(int i=0; i<n; i++) {
            if(rains[i] == 0) {
                dry_days.insert(i);
                ans[i] = 1;
            } else {
                int lake = rains[i];
                if(last_fill.find(lake) != last_fill.end()) {
                    auto it = dry_days.lower_bound(last_fill[lake]);
                    if(it == dry_days.end()) return {};
                    int dry_day = *it;
                    ans[dry_day] = lake;
                    dry_days.erase(dry_day);
                }
                last_fill[lake] = i;
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};
