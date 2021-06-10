class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length(), m = words.size();
        vector<int> idx(m, 0);
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (words[j][idx[j]] == s[i]) {
                    idx[j]++;
                }
            }
        }
        
        int res = 0;
        for (int i=0; i<m; ++i) {
            if (idx[i] == words[i].size()) ++res;
        }
        
        return res;
    }
};
