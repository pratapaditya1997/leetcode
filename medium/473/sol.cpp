typedef pair<int, int> pii;

class Solution {
public:
    int n, reqd;
    map<pii, int> dp;
    
    bool f(int mask, int left, vector<int>& a) {
        if (dp.find({mask, left}) != dp.end()) return dp[{mask, left}];
        if (mask == 0) return (left == 0);
        if (left == 0) return f(mask, reqd, a);
        
        bool res = false;
        for (int i=0; i<n; ++i) {
            if (mask & (1<<i)) {
                // set bit so we can use it
                if (a[i] > reqd) break;
                if (f(mask ^ (1<<i), left - a[i], a)) {
                    res = true;
                    break;
                }
            }
        }
        dp[{mask, left}] = res;
        return res;
    }
    
    bool makesquare(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum % 4 != 0) return false;
        
        n = a.size();
        reqd = sum / 4;
        dp.clear();
        return f((1<<n) - 1, reqd, a);
    }
};
