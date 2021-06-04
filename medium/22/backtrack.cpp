class Solution {
public:
    int n;
    vector<string> ans;
    
    void f(int i, int balance, string& cur) {
        if (balance < 0) return;
        if (i == 2*n) {
            if (balance == 0) {
                ans.push_back(cur);
            }
            return;
        }
        cur += "(";
        f(i+1, balance+1, cur);
        cur.pop_back();
        cur += ")";
        f(i+1, balance-1, cur);
        cur.pop_back();
    }
    
    vector<string> generateParenthesis(int _n) {
        n = _n;
        string cur = "";
        f(0, 0, cur);
        return ans;
    }
};
