class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        a.push_back(INT_MAX);
        
        int n = a.size();
        
        int l = 0, r = n-2, ans = -1;
        while (l <= r) {
            int m = (l+r)/2;
            if (a[m] > a[m+1]) {
                ans = m;
                r = m-1;
            } else l = m+1;
        }
        
        return ans;
    }
};
