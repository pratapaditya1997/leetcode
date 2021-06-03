const int INF = 1e5;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = -INF, b2 = -INF, s1 = -INF, s2 = -INF;
        
        for (int p: prices) {
            b1 = max(b1, -p);
            s1 = max(s1, b1 + p);
            b2 = max(b2, s1 - p);
            s2 = max(s2, b2 + p);
        }
        
        return s2;
    }
};
