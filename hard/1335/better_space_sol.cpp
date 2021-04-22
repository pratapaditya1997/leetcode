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
        
        vector<int> dp_old(n+1, MX), dp_new(n+1, MX);
        auto mx = calculate_range_max(arr);
        
        for (int i=0; i<n; i++) {
            dp_old[i] = mx[0][i];
        }
        
        for (int i=2; i<=d; i++) {
            for (int j = 1; j<n; j++) {
                int best = MX;
                for (int k=0; k<j; k++) {
                    best = min(best, dp_old[k] + mx[k+1][j]);
                }
                dp_new[j] = best;
            }
            dp_old = dp_new;
        }
        
        return dp_old[n-1];
    }
};
