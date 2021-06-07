/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int FindPeak(int n, MountainArray &ma) {
        int l = 0, r = n-1;
        while (r-l > 3) {
            int m1 = l + (r-l)/3;
            int m2 = r - (r-l)/3;
            
            int fm1 = ma.get(m1);
            int fm2 = ma.get(m2);
            
            if (fm1 < fm2) l = m1;
            else if (fm1 > fm2) r = m2;
            else {
                l = m1;
                r = m2;
            }
        }
        
        int best = 0, idx = l;
        for (int i=l; i<=r; ++i) {
            int val = ma.get(i);
            if (val > best) {
                best = val;
                idx = i;
            }
        }
        return idx;
    }
    
    int FindInIncreasing(int l, int r, int target, MountainArray &ma) {
        while (l <= r) {
            int m = (l+r)/2;
            int val = ma.get(m);
            if (val <= target) {
                l = m+1;
                if (val == target) return m;
            } else r = m-1;
        }
        return -1;
    }
    
    int FindInDecreasing(int l, int r, int target, MountainArray &ma) {
        while (l <= r) {
            int m = (l+r)/2;
            int val = ma.get(m);
            if (val >= target) {
                l = m+1;
                if (val == target) return m;
            } else r = m-1;
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &ma) {
        int n = ma.length();
        int peak_idx = FindPeak(n, ma);
        int ans = FindInIncreasing(0, peak_idx, target, ma);
        if (ans != -1) return ans;
        
        ans = FindInDecreasing(peak_idx, n-1, target, ma);
        return ans;
    }
};
