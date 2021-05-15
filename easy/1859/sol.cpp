class Solution {
public:
    string sortSentence(string s) {
        map<int, string> m;
        
        int n = s.size();
        string cur = "";
        for (int i=0; i<n; i++) {
            if (s[i] == ' ') {
                int pos = s[i-1] - '0';
                cur.pop_back();
                m[pos] = cur;
                cur = "";
            } else cur += s[i];
        }
        int pos = s[n-1] - '0';
        cur.pop_back();
        m[pos] = cur;
        cur = "";
        
        for (auto& p: m) cur += (p.second + " ");
        cur.pop_back();
        return cur;
    }
};
