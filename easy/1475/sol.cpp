class Solution {
public:
    vector<int> finalPrices(vector<int>& a) {
        int n = size(a);
        vector<int> less;
        for(int i=0; i<n; i++) {
            while(!less.empty() && a[less.back()] >= a[i]) {
                int idx = less.back();
                a[idx] -= a[i];
                less.pop_back();
            }
            less.push_back(i);
        }
        return a;
    }
};
