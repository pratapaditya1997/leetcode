class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int den = 2; den <= n; den++) {
            for(int num = 1; num < den; num++) {
                int x = __gcd(num,den);
                if(x != 1) continue;
                string str = to_string(num) + "/" + to_string(den);
                ans.push_back(str);
            }
        }
        return ans;
    }
};
