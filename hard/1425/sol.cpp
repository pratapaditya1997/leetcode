class Solution {
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        int n = size(a);
        vector<int> dp(n);
        int ans = a[0];
        
        deque<int> dq(k);
        dq.push_back(0);
        dp[0] = a[0];
        for(int i=1; i<n; i++) {
            while(!dq.empty() && dq.front() < i-k) dq.pop_front();
            dp[i] = a[i];
            dp[i] = max(dp[i], dp[dq.front()] + a[i]);
            ans = max(ans, dp[i]);
            while(!dq.empty() && dp[i] >= dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        return ans;
    }
};
