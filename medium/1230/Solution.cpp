class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int k) {
        int n = (int)prob.size();
        vector<double> dp(n+1);
        
        dp[0] = 1.0; // dp[i] = prob of 'i' heads after some turns
        for(double p: prob) {
            vector<double> newDp(n+1);
            for(int i=0;i<n;i++) {
                newDp[i+1] = dp[i] * p;
                newDp[i] += dp[i] * (1 - p);
            }
            dp = newDp;
        }
        
        return dp[k];
    }
};
