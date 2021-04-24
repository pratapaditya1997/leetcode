class Solution {
public:
    void fill_jump(const vector<pair<int, int>>& v, vector<int>& jump, int n) {
        stack<int> stk;
        for (int i=0; i<n; i++) {
            int idx = v[i].second;
            while(!stk.empty() && stk.top() < idx) {
                jump[stk.top()] = idx;
                stk.pop();
            }
            stk.push(idx);
        }
    }
    
    int oddEvenJumps(vector<int>& a) {
        int n = a.size();
        vector<int> odd_jump(n, -1), even_jump(n, -1);
        
        vector<pair<int, int>> v;
        for (int i=0; i<n; i++) {
            v.push_back({a[i], i});
        }
        sort(v.begin(), v.end());
        fill_jump(v, odd_jump, n);
        
        for (int i=0; i<n; i++) v[i].first *= -1;
        sort(v.begin(), v.end());
        fill_jump(v, even_jump, n);

        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[n-1][0] = dp[n-1][1] = 1;
        
        int ans = 1; 
        for (int i=n-2; i>=0; i--) {
            if (odd_jump[i] != -1) dp[i][1] = dp[odd_jump[i]][0];
            if (even_jump[i] != -1) dp[i][0] = dp[even_jump[i]][1];
            ans += dp[i][1];
        }
        
        return ans;
    }
};
