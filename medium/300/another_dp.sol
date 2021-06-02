const int INF = 1e9;

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        
        vector<int> d(n+1, INF);
        d[0] = -INF;
        
        // loop on numbers
        for (int i=0; i<n; ++i) {
            // loop on lis length
            for (int j=1; j<=n; ++j) {
                if (d[j-1] < a[i] && a[i] < d[j]) {
                    d[j] = a[i];
                }
            }
        }
        
        int ans = 0;
        for (int i=n; i>=1; --i) {
            if (d[i] < INF) return i;
        }  
        return 0;
    }
};
