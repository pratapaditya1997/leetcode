const int inf = 1e5;

class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int n = a.size();
        
        vector<vector<int>> dp_a(n, vector<int>(7, inf));
        vector<vector<int>> dp_b(n, vector<int>(7, inf));
        
        dp_a[0][a[0]] = 0;
        dp_b[0][b[0]] = 0;
        
        dp_a[0][b[0]] = min(dp_a[0][b[0]], 1);
        dp_b[0][a[0]] = min(dp_b[0][a[0]], 1);
        
        for (int i=1; i<n; i++) {
            for (int j=1; j<=6; j++) {
                int x = (a[i] == j) ? 0 : (b[i] == j) ? 1 : inf; 
                if (x != inf) dp_a[i][j] = dp_a[i-1][j] + x;
                
                x = (b[i] == j) ? 0 : (a[i] == j) ? 1 : inf;
                if (x != inf) dp_b[i][j] = dp_b[i-1][j] + x;
            }
        }
        
        int ans = inf;
        for (int j=1; j<=6; j++) {
            ans = min(ans, min(dp_a[n-1][j], dp_b[n-1][j]));
        }
        if (ans >= inf) return -1;
        return ans;
    }
};
