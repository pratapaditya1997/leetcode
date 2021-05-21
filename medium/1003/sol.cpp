class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for (char c: s) {
            int m = stk.size();
            if (c == 'c') {
                if (m>=2 && stk[m-1] == 'b' && stk[m-2] == 'a') {
                    stk.pop_back();
                    stk.pop_back();
                } else return false;
            } else stk.push_back(c);
        }
        return stk.empty();
    }
};
