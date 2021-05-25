vector<vector<int>> g;
vector<int> d;

class Solution {
public:
    bool IsOneOff(const string& s, const string& t) {
        int n = s.length(), off = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] != t[i]) ++off;
            if (off > 1) return false;
        }
        return (off == 1);
    }
    
    int ladderLength(string begin_word, string end_word, vector<string>& words) {
        unordered_map<string, int> m;
        
        int k = 0;
        if (m.find(begin_word) == m.end()) m[begin_word] = k++;
        if (m.find(end_word) == m.end()) m[end_word] = k++;
        
        for (const string& word: words) {
            if (m.find(word) == m.end()) m[word] = k++;
        }
        
        g = vector<vector<int>>(k, vector<int>());
        d = vector<int>(k, -1);

        int n = words.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (IsOneOff(words[i], words[j])) {
                    int ui = m[words[i]], vi = m[words[j]];
                    g[ui].push_back(vi);
                    g[vi].push_back(ui);
                }
            }
        }
        
        for (int i=0; i<n; ++i) {
            if (IsOneOff(begin_word, words[i])) {
                int ui = m[begin_word], vi = m[words[i]];
                g[ui].push_back(vi);
                g[vi].push_back(ui);
            }
        }
        
        int src = m[begin_word], tar = m[end_word];
        queue<int> q;
        q.push(src);
        d[src] = 0; 
        
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int to: g[v]) {
                if (d[to] == -1) {
                    d[to] = d[v] + 1;
                    if (tar == to) return d[to] + 1;
                    q.push(to);
                }
            }
        }
        
        return 0;
    }
};
