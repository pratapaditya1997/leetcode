class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        long long int lo=-1e10, hi=1e10, mid, ans=0;
        
        auto lessThan = [&matrix, &k](long long int mid) {
            int ret = 0;
            for(auto v: matrix) {
                ret += upper_bound(v.begin(), v.end(), mid) - v.begin();
            }
            return ret;
        };
        
        while(lo <= hi) {
            mid = (lo+hi)/2;
            if(lessThan(mid) >= k) {
                hi = mid-1;
                ans = mid;
            } else lo = mid+1;
        }
        
        return ans;
    }
};
