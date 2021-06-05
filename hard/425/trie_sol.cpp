int nodes;
vector<vector<int>> trie;
vector<vector<int>> words_idx;

void init(int len) {
    nodes = 0;
    trie = vector<vector<int>>(len, vector<int>(26, -1));
    words_idx = vector<vector<int>>(len, vector<int>());
}

int AddEdge(int node, char c) {
    int nxt = trie[node][c-'a'];
    if (nxt == -1) {
        nxt = ++nodes;
        trie[node][c-'a'] = nxt;
    }
    return nxt;
}

void Insert(const string& s, int idx) {
    int cur = 0;
    for (char c: s) {
        words_idx[cur].push_back(idx);
        cur = AddEdge(cur, c);
    }
    words_idx[cur].push_back(idx);
}

vector<int> Search(const string& pre) {
    int cur = 0;
    for (char c: pre) {
        int nxt = trie[cur][c-'a'];
        if (nxt == -1) return {};
        cur = nxt;
    }
    return words_idx[cur];
}

class Solution {
public:
    int n;
    vector<vector<string>> ans;
    
    void BuildTrie(vector<string>& words) {
        int len = 0;
        for (auto& word: words) len += word.length();
        
        init(len + 5);
        int m = words.size();
        for (int i=0; i<m; ++i) {
            Insert(words[i], i);
        }
    }
    
    void f(int idx, vector<string>& cur, vector<string>& words) {
        if (idx == n) {
            ans.push_back(cur);
            return;
        }
        
        string pre = "";
        for (auto& str: cur) {
            pre.push_back(str[idx]);
        }
        
        vector<int> options = Search(pre);
        if (options.empty()) return;
        
        for (auto& option: options) {
            cur.push_back(words[option]);
            f(idx+1, cur, words);
            cur.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words[0].length();
        ans.clear();
        
        BuildTrie(words);
        
        for (auto& word: words) {
            vector<string> cur{word};
            f(1, cur, words);
        }
        return ans;
    }
};
