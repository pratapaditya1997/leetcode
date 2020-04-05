class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo=matrix[0][0], hi=matrix[n-1][n-1], mid, ans=0;
        
        auto lessThan = [&matrix, &k](int mid) {
            int ret = 0;
            for(auto v: matrix) {
                ret += upper_bound(v.begin(), v.end(), mid) - v.begin();
            }
            return ret;
        };
        
        while(lo <= hi) {
            mid = lo + (hi-lo)/2;
            if(lessThan(mid) >= k) {
                hi = mid-1;
                ans = mid;
            } else lo = mid+1;
        }
        
        return ans;
    }
};
