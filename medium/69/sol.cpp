using ll = long long int;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = 0;
        while(l <= r) {
            ll m = (l+r)/2;
            if(m*m <= x) {
                l = m+1;
                ans = m;
            } else r = m-1;
        }
        return ans;
    }
};
