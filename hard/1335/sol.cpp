const int MX = 1e5;

class Solution {
public:
    auto calculate_range_max(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> mx(n, vector<int>(n, 0));
        
        for (int i=0; i<n; i++) {
            int val = arr[i];
            for (int j=i; j<n; j++) {
                val = max(val, arr[j]);
                mx[i][j] = val;
            }
        }
        
        return mx;
    }
    
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        if (n < d) return -1;
        
        vector<vector<int>> dp(n+1, vector<int>(d+1, MX));
        auto mx = calculate_range_max(arr);
        
        // base cases
        for (int i=0; i<n; i++) {
            dp[i][0] = 0;
            dp[i][1] = mx[0][i];
        }
        
        for (int i=1; i<n; i++) {
            for (int j = 2; j<=d; j++) {
                int best = MX;
                for (int k=0; k<i; k++) {
                    best = min(best, dp[k][j-1] + mx[k+1][i]);
                }
                dp[i][j] = best;
            }
        }
        
        return dp[n-1][d];
    }
};
