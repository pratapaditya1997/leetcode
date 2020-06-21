class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0, cur = start;
        for(int i=0; i<n; i++)  {
            cur = start + 2*i;
            ans ^= cur;
        }
        return ans;
    }
};
