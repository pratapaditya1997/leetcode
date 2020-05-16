string dp[5001] = {};

string largestNumber(vector<int>& cost, int t) {
    if(t<=0) return t==0 ? "" : "0";
    if(dp[t].empty()) {
        dp[t] = "0";
        for(int d=1; d<=9; d++) {
            string res = largestNumber(cost,t-cost[d-1]);
            if(res != "0" && res.size() + 1 >= dp[t].size()) {
                dp[t] = to_string(n) + res;
            }
        }
    }
    return dp[t];
}