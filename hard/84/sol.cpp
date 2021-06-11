class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> s;
        s.push_back(-1);
        
        int ans = 0;
        for (int i=0; i<n; ++i) {
            while (!s.empty() && s.back() != -1 && a[s.back()] > a[i]) {
                int val = s.back();
                s.pop_back();
                ans = max(ans, a[val] * (i - s.back() - 1));
            }
            s.push_back(i);
        }
        while (!s.empty() && s.back() != -1) {
            int val = s.back();
            s.pop_back();
            ans = max(ans, a[val] * (n - s.back() - 1));
        }
        return ans;
    }
};
