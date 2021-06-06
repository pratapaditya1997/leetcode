class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        stack<int> s, t;
        
        int n = a.size();
        int l = n, r = 0;
        for (int i=0; i<n; ++i) {
            while (!s.empty() && a[s.top()] > a[i]) {
                l = min(l, s.top());
                s.pop();
            }
            s.push(i);
        }
        
        for (int i=n-1; i>=0; --i) {
            while (!t.empty() && a[t.top()] < a[i]) {
                r = max(r, t.top());
                t.pop();
            }
            t.push(i);
        }
        
        if (r - l > 0) return r-l+1;
        return 0;
    }
};
