class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        int n = a.size();
        
        vector<int> dp(n);
        dp[0] = a[0];
        
        deque<int> dq;
        dq.push_back(0); // index
        
        for (int i=1; i<n; ++i) {
            while (!dq.empty() && dq.front() < i-k) dq.pop_front();
            dp[i] = dp[dq.front()] + a[i];
            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[n-1];
    }
};
