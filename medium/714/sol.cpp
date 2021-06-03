class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<int> not_hold(n), hold(n); // not holding or holding a stock at the end of ith day
        
        hold[0] = -p[0], not_hold[0] = 0;
        for (int i=1; i<n; ++i) {
            /**
            * not holding a share at the end of today (ith day)
            * -> not holding share yesterday and did nothing today = not_hold[i-1]
            * -> holding share yesterday and sold it today = hold[i-1] + p[i] - fee
            */
            not_hold[i] = max(not_hold[i-1], hold[i-1] + p[i] - fee);
            
            /**
            * holding a share at the end of today (ith day)
            * -> not holding share yesterday and bought a share today = not_hold[i-1] - p[i]
            * -> holding share yesterday and did nothing today = hold[i-1]
            */
            hold[i] = max(hold[i-1], not_hold[i-1] - p[i]);
        }
        
        // return max profit on the end of last day
        return max(not_hold[n-1], hold[n-1]);
    }
};
