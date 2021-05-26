const int INF = 1e5;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, INF);
        set<int> s(days.begin(), days.end());
        
        dp[0] = 0;
        for (int i=1; i<=365; ++i) {
            if (s.find(i) != s.end()) {
                int val = dp[i-1] + costs[0];
                
                if (i - 7 >= 0) val = min(val, dp[i-7] + costs[1]);
                else val = min(val, costs[1]);
                
                if (i - 30 >= 0) val = min(val, dp[i-30] + costs[2]);
                else val = min(val, costs[2]);
                
                dp[i] = val;
            } else dp[i] = dp[i-1];
        }
        
        return dp[*s.rbegin()];
    }
};
