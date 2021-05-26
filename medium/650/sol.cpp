class Solution {
public:
    int minSteps(int n) {
        int ans = 0, d = 2;
        while (n > 1) {
            while (n % 2 == 0) {
                ans += d;
                n /= d;
            }
            ++d;
        }
        return ans;
    }
};
