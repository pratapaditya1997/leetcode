class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size(), best, keep, drop;
        
        keep = drop = best = arr[0];
        for(int i=1; i<n; i++) {
            drop = max(keep,drop+arr[i]);
            keep = max(keep,0) + arr[i];
            best = max({best, keep, drop});
        }
        return best;
    }
};
