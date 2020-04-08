class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            int cur_width=0, cur_height=0, len=1;
            dp[i] = INT_MAX;
            while(len<=i) {
                cur_width += books[i-len][0];
                cur_height = max(cur_height, books[i-len][1]);
                if(cur_width > shelf_width) break;
                dp[i] = min(dp[i], dp[i-len]+cur_height);
                len++;
            }
        }
        return dp[n];
    }
};
