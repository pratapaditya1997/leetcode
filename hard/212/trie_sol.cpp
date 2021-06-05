int nodes;
vector<vector<int>> trie;
vector<int> words_end, words_count;

void init(int len) {
    nodes = 0;
    words_end.assign(len, 0);
    words_count.assign(len, 0);
    trie = vector<vector<int>>(len, vector<int>(26, -1));
}

int addEdge(int node, char c) {
    int nxt = trie[node][c-'a'];
    if (nxt == -1) {
        nxt = ++nodes;
        trie[node][c-'a'] = nxt;
    }
    return nxt;
}

void insert(const string& s) {
    int cur = 0;
    for (char c: s) {
        ++words_count[cur];
        cur = addEdge(cur, c);
    }
    ++words_count[cur];
    ++words_end[cur];
}

void erase(const string& s) {
    int cur = 0;
    for (char c: s) {
        --words_count[cur];
        int nxt = trie[cur][c-'a'];
        if (words_count[nxt] == 1) {
            trie[cur][c-'a'] = -1;
        }
        cur = nxt;
    }
    
    --words_count[cur];
    --words_end[cur];
}

class Solution {
public:
    int n, m;
    vector<string> ans;
    
    void f(int x, int y, int node, string& cur, vector<vector<char>>& board) {
        if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] == '#') return;
        
        char c = board[x][y];
        int nxt_node = trie[node][c-'a'];
        if (nxt_node == -1) return;
        
        cur.push_back(c);
        if (words_end[nxt_node]) {
            erase(cur); // erase if a word has been found, optimization
            ans.push_back(cur);
        }
        board[x][y] = '#'; // mark cell as visited
        
        f(x+1, y, nxt_node, cur, board);
        f(x-1, y, nxt_node, cur, board);
        f(x, y+1, nxt_node, cur, board);
        f(x, y-1, nxt_node, cur, board);
        
        cur.pop_back();  // reset the state of cur back to original state
        board[x][y] = c; // mark cell again as not visited
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ans.clear();
        
        int total_len = 0;
        for (auto& word: words) total_len += word.length();
        
        init(total_len + 5);
        for (auto& word: words) {
            insert(word);
        }
        
        n = board.size();
        m = board[0].size();
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                string cur = "";
                f(i, j, 0, cur, board);
            }
        }
        
        return ans;
    }
};
