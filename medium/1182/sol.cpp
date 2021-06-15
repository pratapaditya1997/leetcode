const int inf = 1e7;

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& c, vector<vector<int>>& queries) {
        int n = c.size();
        
        vector<vector<int>> nearest(n, vector<int>(4, inf));
        vector<int> prev {-1, -1, -1, -1};
        
        for (int i=0; i<n; ++i) {
            prev[c[i]] = i;
            for (int j=1; j<=3; ++j) {
                if (prev[j] != -1) nearest[i][j] = min(nearest[i][j], abs(i - prev[j]));
            }
        }
        
        prev = {-1, -1, -1, -1};
        for (int i=n-1; i>=0; --i) {
            prev[c[i]] = i;
            for (int j=1; j<=3; ++j) {
                if (prev[j] != -1) nearest[i][j] = min(nearest[i][j], abs(i - prev[j]));
            }
        }
        
        vector<int> res;
        for (auto& q: queries) {
            int i = q[0], c = q[1];
            if (nearest[i][c] >= inf) res.push_back(-1);
            else res.push_back(nearest[i][c]);
        }
        
        return res;
    }
};
