class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if (n == 1) return 0;
        
        vector<int> not_hold(n), hold(n);
        
        hold[0] = -p[0], not_hold[0] = 0;
        hold[1] = -1 * min(p[0], p[1]), not_hold[1] = max(0, p[1] - p[0]);
        for (int i=2; i<n; ++i) {
            not_hold[i] = max(not_hold[i-1], hold[i-1] + p[i]);
            hold[i] = max(hold[i-1], not_hold[i-2] - p[i]);
        }
        
        return max(not_hold[n-1], hold[n-1]);
    }
};
