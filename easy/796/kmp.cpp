class Solution {
public:
    vector<int> PrefixFunction(const string& s) {
        int n = s.length();
        vector<int> pi(n, 0);
        
        for (int i=1; i<n; ++i) {
            int j = pi[i-1];
            while (j>0 && s[i] != s[j]) {
                j = pi[j-1];
            }
            if (s[i] == s[j]) ++j;
            pi[i] = j;
        }
        return pi;
    }
    
    bool rotateString(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int req_len = t.length();
        s += s;
        t += "#" + s;
        
        vector<int> pi = PrefixFunction(t);
        for (int i=req_len; i<t.length(); ++i) {
            if (pi[i] == req_len) return true;
        }
        return false;
    }
};
