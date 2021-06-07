class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n-1;
        while (r-l > 3) {
            int m1 = l + (r-l)/3;
            int m2 = r - (r-l)/3;
            
            int fm1 = a[m1];
            int fm2 = a[m2];
            
            if (fm1 < fm2) l = m1;
            else if (fm1 > fm2) r = m2;
            else {
                l = m1;
                r = m2;
            }
        }
        
        int best = 0, idx = l;
        for (int i=l; i<=r; ++i) {
            int val = a[i];
            if (val > best) {
                best = val;
                idx = i;
            }
        }
        return idx;
    }
};
