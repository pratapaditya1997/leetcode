const int N = 3e4 + 4;
const int ALPHA = 26;

int trie[N][ALPHA];
int nodes;
int words_end_count[N];

void init() {
    nodes = 0;
    memset(trie, -1, sizeof trie);
    memset(words_end_count, 0, sizeof words_end_count);
}

int addEdge(int node, char c) {
    int nxt = trie[node][c - 'a'];
    if (nxt == -1) {
        nxt = ++nodes;
        trie[node][c - 'a'] = nxt;
    }
    return nxt;
}

void insert(string str) {
    int cur = 0;
    for (char c: str) {
        cur = addEdge(cur, c);
    }
    words_end_count[cur]++;
}

void dfs(int node, string& so_far, string& ans) {
    if (so_far.length() > ans.length()) {
        ans = so_far;
    }
    for (int c = 0; c < ALPHA; c++) {
        int nxt = trie[node][c];
        if (nxt != -1 && words_end_count[nxt] > 0) {
            so_far += char('a' + c);
            dfs(nxt, so_far, ans);
            so_far.pop_back();
        }
    }
}

class Solution {
public:
    string longestWord(vector<string>& words) {
        init();
        for (auto& word: words) {
            insert(word);
        }
        
        string ans = "";
        string so_far = "";
        dfs(0, so_far, ans);
        return ans;
    }
};
