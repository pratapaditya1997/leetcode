class Solution {
public:
    int n;
    
    bool Matching(const string& s, const string& t) {
        int i=0;
        for (int j=0; j<t.length(); ++j) {
            while (s[i] != t[j] && i < n) ++i;
            if (i == n) return false;
            ++i;
        }
        return true;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        n = s.length();
        int res = 0;
        for (auto& word: words) {
            if (Matching(s, word)) ++res;
        }
        return res;
    }
};
