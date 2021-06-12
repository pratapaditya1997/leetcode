typedef pair<int, int> pii;

class Solution {
public:
    
    pii GetSlope(pii a, pii b) {
        pii res;
        res.first = -1 * (b.second - a.second); // -(y2 - y1)
        res.second = b.first - a.first;         //  (x2 - x1)
        
        int gcd = __gcd(res.first, res.second);
        if (gcd == 0) return res;
        
        res.first /= gcd;
        res.second /= gcd;
        return res;
    }
    
    int maxPoints(vector<vector<int>>& p) {
        int n = p.size(), ans = 1;
        
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                pii pi = {p[i][0], p[i][1]};
                pii pj = {p[j][0], p[j][1]};
                pii req_slope = GetSlope(pi, pj);
                int cur = 0;
                for (int k=0; k<n; ++k) {
                    pj = {p[k][0], p[k][1]};
                    if (GetSlope(pi, pj) == req_slope) ++cur;
                }
                ans = max(ans, cur + 1);
            }
        }
        
        return ans;
    }
};
