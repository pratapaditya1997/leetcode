class Solution {
public:
    vector<int> shuffle(vector<int>& a, int n) {
        vector<int> ans(2*n);
        int j = 0;
        for(int i=0; i<n; i++, j += 2) {
            ans[j] = a[i];
            ans[j+1] = a[n+i];
        }
        return ans;
    }
};
