class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> dp;
        int ans = 0;
        for(int x: arr) {
            if(dp.find(x-diff) == dp.end()) dp[x] = 1;
            else dp[x] = max(dp[x], dp[x-diff]+1);
            ans = max(ans, dp[x]);
        }
        return ans;
    }
};
