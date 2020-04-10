class Solution {
public:
    int numSteps(string s) {
        int ans = 0, n = s.length(), carry = 0;
        for(int i=n-1; i>0; i--) {
            if(s[i] == '0') {
                if(carry) ans+=2;
                else ans++;
            } else {
                if(carry) ans++;
                else {
                    carry = 1;
                    ans += 2;
                }
            }
        }
        if(carry) ans++;
        return ans;
    }
};
