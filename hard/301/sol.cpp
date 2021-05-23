typedef pair<int, int> pii;

set<string> ans;

class Solution {
public:
    /*
    * this function returns the number of changes required in left & right parentheses 
    * returns {left changes, right changes}
    */
    pii get_min_changes(const string& s) {
        int min_changes = 0, balance = 0;
        for (char c: s) {
            if (c == '(') balance++;
            if (c == ')') {
                balance--;
                if (balance < 0) {
                    min_changes++;
                    balance = 0;
                }
            }
        }
        return {balance, min_changes};
    }
    
    /*
    * checks if a string is balanced
    */
    bool is_valid(const string& s) {
        pii p = get_min_changes(s);
        return (p.first == 0 && p.second == 0);
    }
    
    void f(const string& s, int i, int left_rem, int right_rem, string& cur) {
        if (i == s.length()) {
            if (is_valid(cur)) {
                ans.insert(cur);
            }
            return;
        }
        
        // discard current character case
        if (s[i] == '(' && left_rem > 0) f(s, i + 1, left_rem - 1, right_rem, cur);
        if (s[i] == ')' && right_rem > 0) f(s, i + 1, left_rem, right_rem - 1, cur);
        
        // consider current character
        cur += s[i];
        f(s, i + 1, left_rem, right_rem, cur);
        cur.pop_back();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        pii changes = get_min_changes(s);
        ans.clear();
        string cur = "";
        f(s, 0, changes.first, changes.second, cur);
        
        vector<string> ret;
        for(auto& str: ans) ret.push_back(str);
        return ret;
    }
};
